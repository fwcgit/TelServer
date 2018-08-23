//
//  socket.c
//  TelServer
//
//  Created by fwc on 2018/5/25.
//  Copyright © 2018年 fwc. All rights reserved.
//

#include "socket.h"

int socket_fd = 0;
int sockFD;

int listener_socket()
{
    int err;
    
    sockaddr_IN server_addr;
    
    socket_fd = socket(PF_INET, SOCK_STREAM, 0);
    
    if(socket_fd == -1)
    {
        printf("create socket fail! \r");
        return socket_fd;
    }
    
    memset(&server_addr,0,sizeof(sockaddr_IN));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(LISTENER_PORT);
    
    err = bind(socket_fd, (sockAddr *)&server_addr, sizeof(server_addr));
    
    if(err == -1)
    {
        perror("bind socket fail!");
        return err;
    }
    
    err = listen(socket_fd,BACK_COUNT);
    if (err == -1) {
        printf("listener socket fail! error = %d \r",errno);
        exit(1);
    }
    sockFD = socket_fd;
    return socket_fd;
}

void close_socket(void)
{
	
    close(socket_fd);
}

