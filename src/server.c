//
//  server.c
//  TelServer
//
//  Created by fwc on 2018/5/25.
//  Copyright © 2018年 fwc. All rights reserved.
//

#include "server.h"
#include "client_info.h"
#include "client_table.h"

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
    mapClient.size = 10000;
    
    init_map(&mapClient);
    
    client_tbl_init();
    
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
        printf("send data fail %d\n",fd);
    }
}

void send_user(char *session,char *data,size_t len)
{
    client_info *ci = get_client(session);
    if(NULL != ci)
    {
        send_data(ci->fd, data, len);
    }
    else
    {
        printf("send user no client \n");
    }
}

client_info *get_client_list(int *count)
{
	return client_list(count);
}

void stop_server(void)
{
    
    stop_thread();
    close_socket();
}

