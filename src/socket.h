//
//  socket.h
//  TelServer
//
//  Created by fwc on 2018/5/25.
//  Copyright © 2018年 fwc. All rights reserved.
//

#ifndef socket_h
#define socket_h

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "msg.h"

#define BACK_COUNT  100

typedef struct sockaddr_in sockaddr_IN;
typedef struct sockaddr sockAddr;

extern int sockFD;
extern int LISTENER_PORT;

int listener_socket(void);

void close_socket(void);

#endif /* socket_h */
