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
#include <time.h>

int LISTENER_PORT;

void starp_server(void)
{
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
    
    ssize_t s_len;
    int ret;
    fd_set wfd;
    struct timeval tv;
    
    FD_ZERO(&wfd);
    FD_SET(fd,&wfd);
    tv.tv_sec = 0;
    tv.tv_usec = 100 * 1000;
    
    ret = select(fd+1,NULL , &wfd,NULL,&tv);
    
    if(ret == 0)
    {
        
    }
    else if(ret < 0 )
    {
        
    }
    else
    {
        s_len = write(fd, data, len);
        
        if(s_len == 0 || ret < 0)
        {
            printf("send data fail %d\n",fd);
        }
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

void pack_data(char *data,void *msg,size_t m_len,char *src,size_t s_len)
{
    if(NULL == data || NULL == msg || NULL == src) return;
    
    memcpy(data, msg, m_len);
    memcpy(data+m_len, src, s_len);
}
