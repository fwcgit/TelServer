//
//  cleint_table.h
//  TelServer
//
//  Created by fwc on 2018/8/27.
//  Copyright © 2018年 fwc. All rights reserved.
//

#ifndef cleint_table_h
#define cleint_table_h

#include <stdio.h>
#include "client_info.h"
#include "map.h"

extern hashMap mapClient;
extern fd_set read_set;

void client_tbl_init(void);

void accept_client_tbl(client_info *ci);

int  find_max_fd(void);

void add_fd_set(void);

void force_client_close(client_info *ci);

void ci_close(client_info *ci);

void clear_exist_client(char *key);

void save_client(int fd,char *key);

client_info *client_list(int *count);

client_info *get_client(char *session);
#endif /* cleint_table_h */
