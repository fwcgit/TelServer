//
//  read_thread.c
//  TelServer
//
//  Created by fwc on 2018/5/25.
//  Copyright © 2018年 fwc. All rights reserved.
//

#include "h_thread.h"
#include "client_info.h"
#include "client_table.h"

void* read_client(void *args)
{
    int i                       = 0;
    int maxfd                   = 0;
    int ret                     = 0;
    ssize_t rec                 = 0;
    ssize_t firstDataOffset         = 0;
    ssize_t totalBytes          = 0;
    int packageLen              = 0;
    char buff[1024];
    char *data;
    struct timeval tv;
    package *pk                 = NULL;
    client_info *info           = NULL;
    client_info *tableClient    = NULL;
    int count;
    
    tv.tv_sec = 0;
    tv.tv_usec = 500;
    
    while(is_run())
    {
        FD_ZERO(&read_set);
        FD_SET(sockFD,&read_set);
	    add_fd_set();
        maxfd = find_max_fd();
        maxfd = sockFD > maxfd ? sockFD : maxfd;
        tv.tv_sec = 1;
        tv.tv_usec = 0;
        
        ret = select(maxfd+1,&read_set,NULL,NULL,&tv);
        
        if(ret < 0 )
        {
            sleep(1);
            perror("select read fail ! \n");
        }
        else if(ret == 0)
        {
           // printf("select read time out! \n");
        }
        else
        {
            tableClient = sync_read_mapclient_list(&count,0);
            
            if(NULL != tableClient)
            {
                for(i = 0 ; i < count ;i++)
                {
                    info = tableClient+i;
                    if(FD_ISSET(info->fd,&read_set))
                    {
                        memset(&buff, 0, sizeof(buff));
                        rec = recv(info->fd, buff, sizeof(buff), 0);
                        
                        if(rec > 0)
                        {
                            totalBytes      = 0;
                            firstDataOffset = 0;
                            pk = (package*)malloc(sizeof(package));
                            memset(pk, 0, sizeof(package));
                            
                            if(rec >= sizeof(msg_head))
                            {
                                memcpy(pk, buff, sizeof(msg_head));
                                
                                if(pk->head.ck != M_CK(pk->head))
                                {
                                    printf("no protocol head %s\r\n",buff);
                                    continue;
                                }
                                
                                packageLen = pk->head.len;
                                data = (char *)malloc(sizeof(char)*packageLen);
                                memset(data, 0, packageLen);
                                
                                if(rec > sizeof(package) - sizeof(pk->data))
                                {
                                    firstDataOffset = rec - (sizeof(package) - sizeof(pk->data));
                                    memcpy(data, buff+sizeof(package) - sizeof(pk->data), firstDataOffset);
                                }
                                
                                if(firstDataOffset < packageLen)
                                {
                                    while(totalBytes+firstDataOffset < packageLen)
                                    {
                                        rec = recv(info->fd,data+firstDataOffset+totalBytes,sizeof(buff),0);
                                        if(rec <=0)
                                        {
                                            force_client_close(info);
                                            break;
                                        }
                                        else
                                        {
                                            totalBytes+=rec;
                                        }
                                    }
                                }
                                
                                if(totalBytes+firstDataOffset >= packageLen)
                                {
                                    //memcpy(pk, buff, totalBytes);
                                    pk->fd    = info->fd;
                                    pk->data  = data;
                                    add_list(list, pk);
                                    printf("recv %s Len:%d %p\n",data,packageLen,data);
                                }
                            }
                            
                        }
                        else if(rec <= 0)
                        {
                            force_client_close(info);
                            
                        }
                    }
                }
                
                free(tableClient);
                tableClient = NULL;
            }
        }
    }
    return (void*)NULL;
}

void start_read_thread(void)
{
	pthread_t pid;
	int ret;

	ret = pthread_create(&pid,NULL,read_client,NULL);

	if(ret == 0)
	{
		printf("start_read_thread success\n");
	}
	else
	{
		perror("start_read_thread fail \n");
	}
}
