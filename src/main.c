//
//  main.c
//  TelServer
//
//  Created by fwc on 2018/5/24.
//  Copyright © 2018年 fwc. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "list.h"
#include<string.h>
#include <sys/time.h>
#include "map.h"
#include "server.h"
#include "client_info.h"
#include "msg.h"
unsigned int client_count = 0;

char* int_to_str(int val)
{
    char *str = (char *)malloc(sizeof(char)*10);
    sprintf(str,"%d",val);
    free(str);
    return str;
}

int main(int argc, const char * argv[]) {    
#if 1
	client_info  *table;
	int count;
	int i;
    char sessio[100];
	init_config(28898);
	package msg;
	ir_device irDev;

    starp_server();

    while(1)
    {
        gets(sessio);

        if(strcmp(sessio,"q") == 0)
        {
			stop_server();
            exit(0);
        }
        else if(strstr(sessio,"send"))
        {
			printf("send_user");
           	send_user("123456789", "test session data", 13);
        }
		else if(strstr(sessio,"ls"))
		{
			printf("get_client_list\n");
            count = 0;
			table = get_client_list(&count);
			if(count > 0)
			{
				for(i = 0 ; i < count ;i++)
				{				
					printf("%d-client_id code:%s\n",i+1,(table+i)->code);
				}
				free(table);
			}
	
		}
		else if(strstr(sessio,"irop"))
		{
			memset(&msg,0,sizeof(msg));
			memset(&irDev,0,sizeof(ir_device));
			irDev.cmd = 0xFB;
			irDev.num = 0x01;
			msg.head.type = MSG_TYPE_CMD;
			memcpy(msg.body,(char*)&irDev,sizeof(ir_device));
			msg.fd = 0;
			msg.head.len = sizeof(msg_head)+sizeof(ir_device);

			send_user("h001",(char *)&msg,msg.head.len);
		}
		else if(strstr(sessio,"iroc"))
		{
			memset(&msg,0,sizeof(msg));
			memset(&irDev,0,sizeof(ir_device));
			irDev.cmd = 0xFB;
			irDev.num = 0x00;
			msg.head.type = MSG_TYPE_CMD;
			memcpy(msg.body,(char*)&irDev,sizeof(ir_device));
			msg.fd = 0;
			msg.head.len = sizeof(msg_head)+sizeof(ir_device);

			send_user("h001",(char *)&msg,msg.head.len);

		}
		else if(strstr(sessio,"stu"))
		{
			memset(&msg,0,sizeof(msg));
			msg.head.type = MSG_TYPE_CMD;
			msg.body[0] = 0x3B;
			msg.body[1] = 0xE0;
			msg.body[2] = 0xFA;
			msg.body[3] = 0x02;
			msg.body[4] = 0x0d;
			msg.fd = 0;
			msg.head.len = sizeof(msg_head)+5;

			send_user("h001",(char *)&msg,msg.head.len);

		
		}
    }
#endif
    

    
	return 0;
}
