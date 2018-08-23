//
//  h_thread.h
//  TelServer
//
//  Created by fwc on 2018/5/25.
//  Copyright © 2018年 fwc. All rights reserved.
//

#ifndef h_thread_h
#define h_thread_h
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include "socket.h"
#include "list.h"
#include "server.h"

extern List *list;

void start_thread(int sockfd);

void stop_thread(void);

void start_accept_thread(void);

void start_read_thread(void);

void start_handle_thread(void);

void start_auth_thread(void);

void start_heart_thread(void);

unsigned char is_run(void);

void close_read_client_fd(int fd);

#endif /* h_thread_h */
