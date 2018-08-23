//
//  handle_thread.c
//  TelServer
//
//  Created by fwc on 2018/5/28.
//  Copyright © 2018年 fwc. All rights reserved.
//

#include "h_thread.h"
#include "client_info.h"
#include "errno.h"

void set_client_info(int fd,client_info *ci)
{
    int i = 0;
    client_info *cito;
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

	int i;
    client_info *ci;
    
    for(i = 0 ; i < mapClient.keyMap->count;i++)
    {
        ci = (client_info*)((ListNode *)get_list(mapClient.keyMap, i))->data;
        
        if(ci ->fd == fd)
		{
			remove_list(mapClient.keyMap,i);
			break;
		}
    }

}

void* handle_msg(void *args)
{
    package *pk;
    ListNode *node;
    client_info *ci;
	void *tempNode;

    node= poll_list(list);
   
    while(is_run())
    {
        usleep(500 * 1000);
        
        node = poll_list(list);
        if(node != NULL)
        {
            pk = (package *)node->data;
            
			switch (pk->head.type) {
				case MSG_TYPE_ID:

					if(has_map(&mapClient,pk->body))
					{
						ci = (client_info*)((ListNode *)get_map(&mapClient, pk->body))->data;
						close_read_client_fd(ci->fd);
						remove_map(&mapClient,ci->code);
						clear_list_client(ci->fd);

						printf("exist client %d %s \n",ci->fd,ci->code);

					}

					if(has_map(&mapClient, (char *)&(pk->fd)))
					{
						
						ci = (client_info*)((ListNode *)get_map(&mapClient, (char *)&(pk->fd)))->data;
						ci->isAuth = 1;
						strcpy(ci->code, pk->body);
					
						remove_map(&mapClient, (char *)&(pk->fd));
						put_map(&mapClient, pk->body, ci);
					
						set_client_info(pk->fd,ci);
					
						ci = (client_info*)((ListNode *)get_map(&mapClient, pk->body))->data;
						printf("auth success fd %d code:%s \n",ci->fd,ci->code);
						
					}

					break;
				case MSG_TYPE_CMD:

					break;
				case MSG_TYPE_HEART:
					
				if(has_map(&mapClient,pk->body))
				{
				
					 ci = (client_info*)((ListNode *)get_map(&mapClient, pk->body))->data;
					
					 if(NULL != ci)
					 {
						printf("recv heartbeat %d %s \n",ci->ioTimeout,ci->code);
						ci->ioTimeout = 0;
					 }
					 else
					 {
						printf("recv heartbeat NULL");
					 }

				}
					break;
			}
			
		//	printf("handle msg fd %d--------type:%d---len:%d----buff %s \n",
		//		   pk->fd,pk->head.type,pk->head.len,pk->body);

        	free(pk);   
        }
    }
    
    return(void*)NULL;
}

void start_handle_thread(void)
{
	pthread_t pid;
	int ret;

	ret = pthread_create(&pid,NULL,handle_msg,NULL);

	if(ret == 0)
	{
		printf("start_handle_thread success\n");
	}
	else
	{
		perror("start_handle_thread fail\n");
	}
}

