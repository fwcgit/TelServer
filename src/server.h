//
//  server.h
//  TelServer
//
//  Created by fwc on 2018/5/25.
//  Copyright © 2018年 fwc. All rights reserved.
//

#ifndef server_h
#define server_h
#include "socket.h"
#include "h_thread.h"
#include "map.h"
#include "client_info.h"

extern unsigned int client_count;
extern hashMap mapClient;

void starp_server(void);

void init_config(int port);

void init(void);

void stop_server(void);

void send_data(int fd,char *data,size_t len);

void send_user(char *session,char *data,size_t len);

client_info *get_client_list(int *count);

#endif /* server_h */
