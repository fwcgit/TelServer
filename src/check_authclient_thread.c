//
//  check_authclient_thread.c
//  TelServer
//
//  Created by fwc on 2018/8/2.
//  Copyright © 2018年 fwc. All rights reserved.
//

#include <stdio.h>
#include "h_thread.h"
#include <unistd.h>
#include "server.h"
#include "socket.h"
#include "client_info.h"
#include <string.h>
#include <stdlib.h>

void* run_auth_client(void *args)
{

    int i;
    client_info *ci;
    
    while(is_run())
    {
        sleep(3);
        i = 0;

        for(i = 0; i<mapClient.keyMap->count; i++)
        {
            ci = (client_info*)((ListNode *)get_list(mapClient.keyMap, i))->data;
            
            if(ci->isAuth == 0)
            {
                if(ci->authTimeout >= 3)
                {
                    close_client_fd(ci->fd);
                    remove_map(&mapClient, (char *)&(ci->fd));
                    remove_list(mapClient.keyMap, i);
                    
                    printf("close client no auth timeout fd:%d\n",ci->fd);
                }
                ci->authTimeout++;
            }
        }
        
    }
    return (void *)NULL;
}

void start_auth_thread(void)
{
	pthread_t pid;
	int ret;

	ret = pthread_create(&pid,NULL,run_auth_client,NULL);

	if(ret == 0)
	{
		printf("start_auth_thread success\n");
	}
	else
	{
		perror("start_auth_thread fail\n");
	}


}
