//
//  check_client_thread.c
//  TelServer
//
//  Created by fwc on 2018/8/2.
//  Copyright © 2018年 fwc. All rights reserved.
//

#include <stdio.h>
#include "server.h"
#include "client_info.h"
#include "h_thread.h"

void* run_heartbeat_client(void *args)
{
    int i;
    client_info *ci;
    while(is_run())
    {
        sleep(30);
        
        for(i = 0 ; i < mapClient.keyMap->count ; i++)
        {
            ci = (client_info *)((ListNode *)get_list(mapClient.keyMap, i))->data;
            if(ci->isAuth)
            {
                if(ci->ioTimeout >= 3)
                {
                    
                    printf("no heartbeat close client fd:%d code:%s \n",ci->fd,ci->code);
                    close_read_client_fd(ci->fd);
                    remove_map(&mapClient, ci->code);
                    remove_list(mapClient.keyMap, i);
                    
                }
                else
                {
                    ci->ioTimeout++;
                }
            }

        }
        
    }
    return (void *)NULL;
}

void start_heart_thread(void)
{
	pthread_t pid;
	int ret;

	ret = pthread_create(&pid,NULL,run_heartbeat_client,NULL);

	if(ret == 0)
	{
		printf("start_heart_thread success\n");
	}
	else
	{
		perror("start_heart_thread fail\n");
	}
}
