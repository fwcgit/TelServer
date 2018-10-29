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
#include "client_table.h"

void* run_heartbeat_client(void *args)
{
    int i;
    client_info *ci = NULL;
    client_info *tableClient = NULL;
    int count = 0;
    while(is_run())
    {
        sleep(5);
        
        tableClient = sync_read_mapclient_list(&count,1);
        if(NULL != tableClient)
        {
            for(i = 0 ; i < count ; i++)
            {
                ci = (client_info *)(tableClient+i);
                if(ci->isAuth == 1)
                {
                    if(ci->ioTimeout >= 3)
                    {
                        printf("no heartbeat close client fd:%d code:%s \n",ci->fd,ci->code);
                        force_client_close(ci);
                    }
                    else
                    {
                        sync_heartbeat_set(ci->code);
                    }
                }
            }
            
            free(tableClient);
            tableClient = NULL;
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
