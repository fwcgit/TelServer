//
//  cleint_table.c
//  TelServer
//
//  Created by fwc on 2018/8/27.
//  Copyright © 2018年 fwc. All rights reserved.
//

#include "client_table.h"
#include "map.h"
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

pthread_rwlock_t rw_lock;

hashMap mapClient;
fd_set read_set;

hashMap *use_wr_mapclient(void)
{
    hashMap *hm;
    pthread_rwlock_wrlock(&rw_lock);
    hm = &mapClient;
    pthread_rwlock_unlock(&rw_lock);
    
    return hm;
}

hashMap *use_rw_mapclient(void)
{
    hashMap *hm;
    pthread_rwlock_rdlock(&rw_lock);
    hm = &mapClient;
    pthread_rwlock_unlock(&rw_lock);
    
    return hm;
}

/***
 同步读取客户端列表
 **/
int sync_read_mapclient_list(client_info **lci,char isAuth)
{
    int i = 0;
    void *obj = NULL;
    client_info *ci = NULL;
    int count = 0;
    int ret = -1;
    
    ret = pthread_rwlock_rdlock(&rw_lock);
    
    if(ret == 0)
    {
        count = mapClient.keyMap->count;
        *lci = (client_info *)malloc(sizeof(client_info) * count);
        for(i = 0 ; i < count;i++)
        {
            obj = get_list(mapClient.keyMap, i);
            if(NULL != obj)
            {
                ci = (client_info *)((ListNode *)obj)->data;
                if(isAuth)
                {
                    if(ci->isAuth){
                        memcpy(*lci+i, ci, sizeof(client_info));
                    }
                }
                else
                {
                    memcpy(*lci+i, ci, sizeof(client_info));
                }
                
            }
        }
        pthread_rwlock_unlock(&rw_lock);
    }
    
    if(count == 2)
    {
        printf("------->>>client list val %s \n",*lci == NULL ? "NULL":(*lci)->code);

    }
    
    return count;
}

/***
 同步移除没有认证的客户端
 **/
int sync_remove_auth_timeout_client(int *fds,int len)
{
    int i               = 0;
    int n               = 0;
    int ret             = -1;
    int *delIndex       = NULL;
    int index           = 0;
    void *obj           = NULL;
    client_info *info   = NULL;
    
    if(NULL != fds)
    {
        ret = pthread_rwlock_rdlock(&rw_lock);
        
        if(ret == 0)
        {
            delIndex = (int *)malloc(sizeof(int) * len);
            
            for(i = 0 ; i < mapClient.keyMap->count ; i++)
            {
                obj = get_list(mapClient.keyMap, i);
                if(NULL != obj)
                {
                    info = (client_info*)((ListNode *)obj)->data;
                }
                
                if(NULL != info)
                {
                    for(n = len -1; n >= 0 ;n--)
                    {
                        if(info->fd == *(fds+n))
                        {
                            *(delIndex+index) = i;
                        }
                    }
                }
                
                obj     = NULL;
                info    = NULL;
            }
            
            pthread_rwlock_unlock(&rw_lock);
            
            ret = pthread_rwlock_wrlock(&rw_lock);
            if(ret == 0)
            {
                if(NULL != delIndex)
                {
                    for( i = 0 ; i < index ; i++)
                    {
                        remove_list(mapClient.keyMap, *(delIndex+i));
                    }
                }
                
                pthread_rwlock_unlock(&rw_lock);
            }
            else
            {
                printf("sync_remove_auth_timeout_client wrlock fail! \n");
                return -1;
            }
        
        }
        else
        {
            printf("sync_remove_auth_timeout_client rdlock fail! \n");
            return -1;
        }
        
    }
    return 0;
}

/***
 同步查找没有认证的客户端
 **/
int sync_find_auth_timeout_client(int *fds)
{
    int ret = -1;
    int i   = 0;
    int index = 0;
    void *obj = NULL;
    client_info *info = NULL;
    time_t rawtime;
    
    time(&rawtime);
    ret = pthread_rwlock_rdlock(&rw_lock);
    
    if(ret == 0)
    {
        for( i = 0 ; i < mapClient.keyMap->count ; i++)
        {
            obj = get_list(mapClient.keyMap, i);
            if(NULL != obj)
            {
                info = (client_info *)((ListNode *)obj)->data;
                if(NULL != info)
                {
                    if(info->isAuth == 0)
                    {
                        if(rawtime - info->ctime >= 10)
                        {
                             *(fds+index) = info->fd;
                        }
                    }
                }
            }
        }
        pthread_rwlock_unlock(&rw_lock);
    }
    else
    {
        printf("sync_find_auth_timeout_client rdlock fail! \n");
        return -1;
    }
    
    return index;
}

/***
 同步移除列表中的客户端
 **/
int sync_remove_list_client(int fd)
{
    int ret = - 1;
    int removeIndex = -1;
    int i = 0;
    client_info *info;
    void *obj;
    
    ret = pthread_rwlock_rdlock(&rw_lock);
    if(ret == 0)
    {
        for( i = 0 ; i < mapClient.keyMap->count ; i++)
        {
            obj = get_list(mapClient.keyMap, i);
            if(NULL != obj)
            {
                info = (client_info *)((ListNode *)obj)->data;
                if(NULL != info)
                {
                    if(info->fd == fd)
                    {
                        removeIndex = i;
                        break;
                    }
                }
            }
        }
        pthread_rwlock_unlock(&rw_lock);
        ret = pthread_rwlock_wrlock(&rw_lock);
        if(ret == 0)
        {
            remove_list(mapClient.keyMap, removeIndex);
            pthread_rwlock_unlock(&rw_lock);
        }
        else
        {
            printf("sync_remove_list_client wrlock fail\n");
            return -1;
        }
       
        
    }
    else
    {
        printf("sync_remove_list_client rdlock fail\n");
        return -1;
    }
    
    return 0;
}

/***
 同步处理心跳次数
 **/
int sync_heartbeat_set(char *key)
{
    int ret = -1;
    void *obj = NULL;
    client_info *info = NULL;
    
    ret = pthread_rwlock_rdlock(&rw_lock);
    if(ret == 0)
    {
        obj = get_map(&mapClient, key);
        if(NULL != obj)
        {
            info = (client_info *)((ListNode *)obj)->data;
            pthread_rwlock_unlock(&rw_lock);
            ret = pthread_rwlock_wrlock(&rw_lock);
            if(ret == 0)
            {
                info->ioTimeout++;
                pthread_rwlock_unlock(&rw_lock);
                return info->fd;
            }
            else
            {
                printf("sync_heartbeat_handle rdlock fail \n");
                return -1;
            }
            
        }
        else
        {
            pthread_rwlock_unlock(&rw_lock);
        }
        
    }
    else
    {
        printf("sync_heartbeat_handle rdlock fail \n");
        return -1;
    }
    
    return 0;
}

/***
 同步处理心跳
 **/
int sync_heartbeat_handle(char *key)
{
    int ret = -1;
    void *obj = NULL;
    client_info *info = NULL;
    
    ret = pthread_rwlock_rdlock(&rw_lock);
    if(ret == 0)
    {
        obj = get_map(&mapClient, key);
        if(NULL != obj)
        {
            info = (client_info *)((ListNode *)obj)->data;
            pthread_rwlock_unlock(&rw_lock);
            ret = pthread_rwlock_wrlock(&rw_lock);
            if(ret == 0)
            {
                info->ioTimeout = 0;
                pthread_rwlock_unlock(&rw_lock);
                return info->fd;
            }
            else
            {
                printf("sync_heartbeat_handle rdlock fail \n");
                return -1;
            }
            
        }
        else
        {
             pthread_rwlock_unlock(&rw_lock);
        }
        
    }
    else
    {
        printf("sync_heartbeat_handle rdlock fail \n");
        return -1;
    }
    
    return 0;
}

/***
 同步获取客户端数量
 **/
int sync_get_client_count(void)
{
    int ret = -1;
    int count = 0;
    ret = pthread_rwlock_rdlock(&rw_lock);
    count = mapClient.keyMap->count;
    pthread_rwlock_unlock(&rw_lock);
    return count;
}

void set_client_info(int fd,client_info *ci)
{
    int i               = 0;
    client_info *cito   = NULL;
    
    for(i = 0 ;i < mapClient.keyMap->count ;i++)
    {
        cito = (client_info *)((ListNode *)get_list(mapClient.keyMap, i))->data;
        if(fd == cito->fd)
        {
            memcpy(cito, ci, sizeof(client_info));
            break;
        }
    }
}

void clear_list_client(int fd)
{
    
    int i           = 0;
    client_info *ci = NULL;
    
    for(i = 0 ; i < mapClient.keyMap->count;i++)
    {
        if(NULL != get_list(mapClient.keyMap, i))
        {
            ci = (client_info*)((ListNode *)get_list(mapClient.keyMap, i))->data;
            
            if(ci ->fd == fd)
            {
                remove_list(mapClient.keyMap, i);
                printf("clear_list_client fd:%d code:%s\n",ci->fd,ci->code);
                break;
            }
        }
        
    }
    
}

void client_tbl_init(void)
{
    mapClient.size = 10000;
    init_map(&mapClient);
    pthread_rwlock_init(&rw_lock, NULL);
}

int accept_client_tbl(client_info *ci)
{
    int ret = -1;
    time_t rawtime;
    time(&rawtime);
    
    ci->ctime = rawtime;
    
    ret = pthread_rwlock_wrlock(&rw_lock);
    if(ret == 0)
    {
        put_map(&mapClient, (char *)&(ci->fd),ci);
        add_list(mapClient.keyMap, ci);
        pthread_rwlock_unlock(&rw_lock);
    }
    else
    {
        printf("accept_client_tbl wrlock fail !\n");
        return -1;
    }

    
    return 0;
}

void add_fd_set()
{
    int i           = 0;
    client_info *ci = NULL;
    client_info *tableClient = NULL;
    int count = 0;
    int ret = -1;
    
    count = sync_read_mapclient_list(&tableClient,0);
    
    ret = pthread_rwlock_rdlock(&rw_lock);
    
    if(ret == 0)
    {
        for(i = 0 ; i < count;i++)
        {
            ci = (client_info*)((ListNode *)tableClient+i);
            
            FD_SET(ci->fd,&read_set);
        }
        
        if(NULL != tableClient)
        {
            free(tableClient);
            tableClient = NULL;
        }
        
        pthread_rwlock_unlock(&rw_lock);
    }
    else
    {
        printf("add_fd_set rdlock fail !\n");
    }
}

int  find_max_fd()
{
    int i           = 0;
    client_info *ci = NULL ;
    client_info *tableClient = NULL;
    int maxfd       = 0;
    int ret = -1;
    int count = 0;
    
     ret = pthread_rwlock_rdlock(&rw_lock);
    
    if(ret == 0)
    {
        count = sync_read_mapclient_list(&tableClient,0);
        for(i = 0 ; i < count;i++)
        {
            ci = (client_info*)((ListNode *)tableClient+i);
            
            if(maxfd < ci->fd)
                maxfd = ci->fd;
        }
        
        if(NULL != tableClient)
        {
            free(tableClient);
            tableClient = NULL;
        }
        
        pthread_rwlock_unlock(&rw_lock);
        
    }
    else
    {
        printf("find_max_fd rdlock fail !\n");
        return 0;
    }
   
    return maxfd;
}


void force_client_close(client_info *ci)
{
    int ret;
    
    if(NULL != ci)
    {
        printf("force_client_close fd:%d \n",ci->fd);
        FD_CLR(ci->fd,&read_set);
        close(ci->fd);
        sync_remove_list_client(ci->fd);
        
        if(ci->isAuth)
        {
            ret = pthread_rwlock_wrlock(&rw_lock);
            if(ret == 0)
            {
                remove_map(&mapClient, ci->code);
                pthread_rwlock_unlock(&rw_lock);
            }
        }

    }
    
}

void clear_exist_client(char *key)
{
    client_info *ci = NULL;
    int ret = 0;
    
    ret = pthread_rwlock_rdlock(&rw_lock);
    if(ret == 0)
    {
        if(has_map(&mapClient,key))
        {
            if(NULL != get_map(&mapClient, key))
            {
                ci = (client_info*)((ListNode *)get_map(&mapClient, key))->data;
                FD_CLR(ci->fd,&read_set);
                close(ci->fd);
                
                pthread_rwlock_unlock(&rw_lock);
                
                force_client_close(ci);
                
                printf("exist client %d %s \n",ci->fd,ci->code);
            }
            else
            {
                pthread_rwlock_unlock(&rw_lock);
            }
        }
        else
        {
            pthread_rwlock_unlock(&rw_lock);
        }
        
    }
    //pthread_rwlock_unlock(&rw_lock);

}
void save_client(int fd,char *key)
{
    int ret = -1;
    client_info *ci = NULL;
    
    ret = pthread_rwlock_rdlock(&rw_lock);
    if(ret == 0)
    {
        if(has_map(&mapClient, (char *)&fd))
        {
            
            if(strlen(key) <= 24)
            {
                if(NULL != get_map(&mapClient, (char *)&fd))
                {
                    ci = (client_info*)((ListNode *)get_map(&mapClient, (char *)&fd))->data;
                    pthread_rwlock_unlock(&rw_lock);
                    
                    ret = pthread_rwlock_wrlock(&rw_lock);
                    if(ret == 0)
                    {
                        ci->isAuth = 1;
                        ci->fd = fd;
                        strcpy(ci->code, key);
                        remove_map(&mapClient, (char *)&fd);
                        put_map(&mapClient, ci->code, ci);
                        pthread_rwlock_unlock(&rw_lock);
                    }
                    else
                    {
                        pthread_rwlock_unlock(&rw_lock);
                    }
                    
                    printf("auth success fd %d code:%s \n",ci->fd,ci->code);
                }
                
            }else
            {
                pthread_rwlock_unlock(&rw_lock);
            }
        }
        else
        {
            pthread_rwlock_unlock(&rw_lock);
        }
    }
    else
    {
        printf("save_client rdlock fail! \n");
    }

}

client_info *client_list(int *count)
{
    int i               = 0;
    client_info *table  = NULL;
    client_info *ci     = NULL;
    
    if(mapClient.keyMap->count <= 0)
    {
        return 0;
    }
    
    table = (client_info *)malloc(sizeof(client_info) * mapClient.keyMap->count);
    *count = mapClient.keyMap->count;
    printf("get_client_list count:%d \n",mapClient.keyMap->count);
    
    pthread_rwlock_rdlock(&rw_lock);
    
    for(i = mapClient.keyMap->count-1 ; i >= 0 ; i--)
    {
        ci = (client_info*)((ListNode *)get_list(mapClient.keyMap,i))->data;
        if(ci->isAuth)
        {
            memcpy(table+i,ci,sizeof(client_info));
            //strcpy((table+i)->code,ci->code);
        }
    }
    
    pthread_rwlock_unlock(&rw_lock);
    
    return table;
}

client_info *get_client(char *session)
{
    void *obj       = NULL;
    client_info *ci = NULL;
    
    if(NULL !=get_map(&mapClient,session))
    {
        obj = ((ListNode *)get_map(&mapClient,session))->data;
        if(NULL != obj)
        {
            ci = (client_info*)obj;
            return ci;
        }
    }
    else
    {
        printf("send user no client \n");
    }
    
    return NULL;
}
       
