//
//  server.c
//  TelServer
//
//  Created by fwc on 2018/5/25.
//  Copyright © 2018年 fwc. All rights reserved.
//

#include "server.h"
#include "client_info.h"

hashMap mapClient;
int LISTENER_PORT;


void close_all_client()
{
	
	int i;
    client_info *ci;
    
    for(i = 0 ; i < mapClient.keyMap->count;i++)
    {
        ci = (client_info*)((ListNode *)get_list(mapClient.keyMap, i))->data;
        
        close(ci->fd);
    }
}

void starp_server(void)
{
    mapClient.size = 100;
    
    init_map(&mapClient);
    
    int fd = listener_socket();
    if(fd > 0)
    {
      start_thread(fd);
    }
    
}

void init_config(int port)
{
	LISTENER_PORT = port;
}

void init(void)
{
	LISTENER_PORT = 28866;
}

void send_data(int fd,char *data,size_t len)
{
    ssize_t ret;
    
    ret = write(fd, data, len);
    
    if(ret == 0 || ret < 0)
    {
        
    }
}

void send_user(char *session,char *data,size_t len)
{
	void *obj;
    client_info *ci;
    
	if(NULL !=get_map(&mapClient,session))
	{
		obj = ((ListNode *)get_map(&mapClient,session))->data;
		if(NULL != obj)
		{
			ci = (client_info*)obj;
			send_data(ci->fd, data, len);
		}
	}
	else
	{
		printf("send user no client \n");
	}
}

client_info *get_client_list(int *count)
{
	int i;
	client_info *table;
	client_info *ci;

	if(mapClient.keyMap->count <= 0)
	{
		return 0;
	}

	table = (client_info *)malloc(sizeof(client_info) * mapClient.keyMap->count);
	*count = mapClient.keyMap->count;
	printf("get_client_list count:%d \n",mapClient.keyMap->count);

	for(i = mapClient.keyMap->count-1 ; i >= 0 ; i--)
	{

		ci = (client_info*)((ListNode *)get_list(mapClient.keyMap,i))->data;
		printf("ci auth%d fd%d %s \n",ci->isAuth,ci->fd,ci->code);
		if(ci->isAuth)
		{
			memcpy(table+i,ci,sizeof(client_info));
			//strcpy((table+i)->code,ci->code);
		}
	}
	
	//printf("table %d %s %p \n",table->fd,table->code,&table);
	return table;
}

void stop_server(void)
{
    
    stop_thread();
    close_socket();
	close_all_client();
}

