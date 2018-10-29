//
//  client_info.h
//  TelServer
//
//  Created by fwc on 2018/8/2.
//  Copyright © 2018年 fwc. All rights reserved.
//

#ifndef client_info_h
#define client_info_h

typedef struct clientInfo
{
    int fd;
    char isAuth;
    char code[24];
    long ctime;
    int ioTimeout;
    
} client_info;

#endif /* client_info_h */
