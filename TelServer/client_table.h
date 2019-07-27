//
//  cleint_table.h
//  TelServer
//
//  Created by fwc on 2018/8/27.
//  Copyright © 2018年 fwc. All rights reserved.
//

#ifndef cleint_table_h
#define cleint_table_h

#include "client_info.h"
#include "map.h"


extern fd_set read_set;

void client_tbl_init(void);

int accept_client_tbl(client_info *ci);

int  find_max_fd(void);

void add_fd_set(void);

void force_client_close(client_info *ci);

void clear_exist_client(char *key);

void save_client(int fd,char *key);

client_info *client_list(int *count);

client_info *get_client(char *session);

hashMap *use_wr_mapclient(void);

hashMap *use_rd_mapclient(void);

/**------------------**/
void ** sync_read_mapclient_list(int *size,char isAuth);

int sync_find_auth_timeout_client(int *fds);

int sync_get_client_count(void);

int sync_remove_list_client(int fd);

int sync_heartbeat_handle(char *key);

int sync_heartbeat_set(char *key);

int sync_free_client(int *fds,int len);

#endif /* cleint_table_h */
