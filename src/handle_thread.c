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
#include "client_table.h"
#include <time.h>

void get_time_str(char *buff)
{
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    printf("%ld\n", rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buff,30,"Now is %Y/%m/%d %H:%M:%S",timeinfo);
    
}

void* handle_msg(void *args)
{
    package *pk = NULL;
    ListNode *node = NULL;
    client_info *ci = NULL;
	void *tempNode = NULL;
    char buffTime[100];
    
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

                    clear_exist_client(pk->body);
                    
                    save_client(pk->fd, pk->body);

					break;
				case MSG_TYPE_CMD:

					break;
				case MSG_TYPE_HEART:
					
				if(has_map(&mapClient,pk->body))
				{
				
                    tempNode = get_map(&mapClient, pk->body);
                    if(NULL != tempNode)
                    {
                        ci = (client_info*)((ListNode *)tempNode)->data;
                    }
                   
                    if(NULL != ci)
                    {
						printf("recv heartbeat %d %s \n",ci->ioTimeout,ci->code);
						ci->ioTimeout = 0;
                
                        memset(buffTime, 0, sizeof(buffTime));
                        get_time_str(buffTime);
                        strcat(buffTime, ":qACK RECE");
                        send_user(ci->code, buffTime, strlen(buffTime));
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

