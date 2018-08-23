//
//  read_thread.c
//  TelServer
//
//  Created by fwc on 2018/5/25.
//  Copyright © 2018年 fwc. All rights reserved.
//

#include "h_thread.h"
#include "client_info.h"

fd_set read_set;

void add_fd_set(fd_set *fds)
{
	int i;
    client_info *ci;
    
    for(i = 0 ; i < mapClient.keyMap->count;i++)
    {
        ci = (client_info*)((ListNode *)get_list(mapClient.keyMap, i))->data;
        
        FD_SET(ci->fd,fds);
    }
    
}

int  find_max_fd(int sockfd)
{
	int i;
    client_info *ci;
    int maxfd = sockfd;

    for(i = 0 ; i < mapClient.keyMap->count;i++)
    {
        ci = (client_info*)((ListNode *)get_list(mapClient.keyMap, i))->data;
        
        if(maxfd < ci->fd)
            maxfd = ci->fd;
    }
    
    return maxfd;
}

void setFds(void)
{
    
}


void clearClient(int fd,int index)
{
	printf("client close %d \n",fd);

	remove_map(&mapClient,(char *)&fd);
	
	FD_CLR(fd,&read_set);
	remove_list(mapClient.keyMap, index);
	close(fd);
}

void* read_client(void *args)
{
    int i = 0;
	int j = 0;
    int maxfd = 0;
    int ret = 0;
    ssize_t rec = 0;
    char buff[1024];
	ssize_t totalBytes;
	int packageLen;
    struct timeval tv;
    package *pk;
    client_info *ci;
    
    tv.tv_sec = 0;
    tv.tv_usec = 500;
    
    while(is_run())
    {
        FD_ZERO(&read_set);
        FD_SET(sockFD,&read_set);
	    add_fd_set(&read_set);
        maxfd = find_max_fd(sockFD);
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
            for(i = 0 ; i < mapClient.keyMap->count ;i++)
            {
                ci = (client_info*)((ListNode *)get_list(mapClient.keyMap, i))->data;
                
                if(FD_ISSET(ci->fd,&read_set))
                {
                    memset(&buff, 0, sizeof(buff));
                    rec = recv(ci->fd, buff, sizeof(buff), 0);
                    
                    if(rec > 0)
                    {
						totalBytes = rec;

						pk = (package*)malloc(sizeof(package));
                        memset(pk, 0, sizeof(package));

                        if(rec >= sizeof(msg_head))
                        {
							packageLen = buff[1]&0x000000ff;
							
							while(totalBytes < packageLen)
							{
								rec = recv(ci->fd,buff+totalBytes,sizeof(buff)-totalBytes,0);
								if(rec <=0)
								{
									clearClient(ci->fd,i);
									break;
								}
								else
								{
									totalBytes+=rec;
								}
							}

							for(j = 0 ; j < totalBytes ; j++)
							{
								//printf("%X",buff[j]);
							}

							if(totalBytes >= packageLen)
							{
								memcpy(pk, buff, totalBytes);
								pk->fd = ci->fd;
								add_list(list, pk);
								//printf("recv %s Len:%d \n",buff,packageLen);
							}	
                        }
                        
                    }
                    else if(rec <= 0)
                    {
                        printf("client close %d \n",ci->fd);
                    
                        if(ci->isAuth)
                        {
                            remove_map(&mapClient,ci->code);
                        }
                        else
                        {
                            remove_map(&mapClient,(char *)&(ci->fd));
                        }
                        
                        FD_CLR(ci->fd,&read_set);
                        remove_list(mapClient.keyMap, i);
                        close(ci->fd);
                        
                    }
                }
            }
        }
    }
    return (void*)NULL;
}

void close_client_fd(int fd)
{
    FD_CLR(fd,&read_set);
    close(fd);
	printf("read close fd%d \n",fd);
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