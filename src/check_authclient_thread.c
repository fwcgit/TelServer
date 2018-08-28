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
#include "client_table.h"
void* run_auth_client(void *args)
{


    int count;
    int *fds = NULL;
    
    while(is_run())
    {
        sleep(3);
        
        count = sync_get_client_count();
        fds = (int *)malloc(sizeof(int) * count);
        memset(fds, -1, count);
        
        count = sync_find_auth_timeout_client(fds);
        
        if(count > 0)
        {
            sync_free_client(fds, count);
            printf("kill no auth client \n");
        }
        
        free(fds);        
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
