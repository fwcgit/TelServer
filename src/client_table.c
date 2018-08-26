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

pthread_rwlock_t rw_lock;

hashMap mapClient;
fd_set read_set;

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
#if 0
    for(i = 0 ;i < mapClient.keyMap->count ;i++)
    {
        cito = (client_info *)((ListNode *)get_list(mapClient.keyMap, i))->data;
        
        printf("client info fd:%d isAuth:%d\n",cito->fd,cito->isAuth);
        break;
    }
#endif
    
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

void del_client(int fd,char *key)
{
    pthread_rwlock_wrlock(&rw_lock);
    
    remove_map(&mapClient,key);
    
    if(fd > 0)
    {
        clear_list_client(fd);
    }
    pthread_rwlock_unlock(&rw_lock);
}

void insert_client(int type,client_info *ci,char *key)
{
    pthread_rwlock_wrlock(&rw_lock);
    
    if(type == 0)
    {
        put_map(&mapClient, key, ci);
        set_client_info(ci->fd,ci);
        del_client(0, (char *)&(ci->fd));
        
    }else if(type == 1)
    {
        put_map(&mapClient, key, ci);
        set_client_info(ci->fd,ci);
        del_client(ci->fd, (char *)&(ci->fd));
    }
    else
    {
        put_map(&mapClient, (char *)&(ci->fd),ci);
        add_list(mapClient.keyMap, ci);
    }
    
    pthread_rwlock_unlock(&rw_lock);
}

void client_tbl_init(void)
{
    pthread_rwlock_init(&rw_lock, NULL);
}

void accept_client_tbl(client_info *ci)
{

    insert_client(3, ci, "");
    
}

void add_fd_set()
{
    int i           = 0;
    client_info *ci = NULL;

    pthread_rwlock_rdlock(&rw_lock);
    
    for(i = 0 ; i < mapClient.keyMap->count;i++)
    {
        ci = (client_info*)((ListNode *)get_list(mapClient.keyMap, i))->data;
        
        FD_SET(ci->fd,&read_set);
    }
    
    pthread_rwlock_unlock(&rw_lock);
}

int  find_max_fd()
{
    int i           = 0;
    client_info *ci = NULL ;
    int maxfd       = 0;
    
    pthread_rwlock_rdlock(&rw_lock);
    for(i = 0 ; i < mapClient.keyMap->count;i++)
    {
        ci = (client_info*)((ListNode *)get_list(mapClient.keyMap, i))->data;
        
        if(maxfd < ci->fd)
            maxfd = ci->fd;
    }
    pthread_rwlock_unlock(&rw_lock);
    return maxfd;
}


void force_client_close(client_info *ci)
{
    
    if(NULL != ci)
    {
        printf("force_client_close fd:%d \n",ci->fd);
        FD_CLR(ci->fd,&read_set);
        
        if(ci->isAuth)
        {
            del_client(ci->fd,(char *)&(ci->fd));
        }
        else
        {
            del_client(ci->fd,ci->code);
        }
        
        close(ci->fd);
    }
    
}

void ci_close(client_info *ci)
{
    
    printf("ci_close client close %d \n",ci->fd);
    
    FD_CLR(ci->fd,&read_set);
    
    if(ci->isAuth)
    {
        del_client(ci->fd, ci->code);
    }
    else
    {
        del_client(ci->fd, (char*)&(ci->fd));
    }
    
    close(ci->fd);
    
}

void clear_exist_client(char *key)
{
    client_info *ci = NULL;
    int ret = 0;
    
    //pthread_rwlock_rdlock(&rw_lock);
    
    ret = has_map(&mapClient,key);
    if(ret > 0)
    {
        if(NULL != get_map(&mapClient, key))
        {
            ci = (client_info*)((ListNode *)get_map(&mapClient, key))->data;
            
            del_client(ci->fd, ci->code);
            FD_CLR(ci->fd,&read_set);
            close(ci->fd);
            
            printf("exist client %d %s \n",ci->fd,ci->code);
        }
    }
    
    //pthread_rwlock_unlock(&rw_lock);

}
void save_client(int fd,char *key)
{
    client_info *ci = NULL;
    if(has_map(&mapClient, (char *)&fd))
    {
        
        if(strlen(key) <= 24)
        {
            if(NULL != get_map(&mapClient, (char *)&fd))
            {
                ci = (client_info*)((ListNode *)get_map(&mapClient, (char *)&fd))->data;
                ci->isAuth = 1;
                ci->fd = fd;
                strcpy(ci->code, key);
                
                insert_client(0, ci, key);
                
                ci = (client_info*)((ListNode *)get_map(&mapClient, key))->data;
                printf("auth success fd %d code:%s \n",ci->fd,ci->code);
            }

        }
        
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
       
