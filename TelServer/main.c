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
#include "crc.h"

unsigned int client_count = 0;
char *key = "Print0001";

char* int_to_str(int val)
{
    char *str = (char *)malloc(sizeof(char)*10);
    sprintf(str,"%d",val);
    free(str);
    return str;
}

void pack_data(char *data,void *msg,size_t m_len,char *src,size_t s_len)
{
    if(NULL == data || NULL == msg || NULL == src) return;
    
    memcpy(data, msg, m_len);
    memcpy(data+m_len, src, s_len);
}

void send_test_data(void)
{
    char text[4096 * 10];

    package msg;
    msg.fd = 0;
    memset(text, 'C', 4096 * 10);
    msg.head.type = MSG_TYPE_DATA;
    msg.head.len = 4096 * 10;
    msg.head.ck  = M_CK(msg.head);
    msg.head.crc  = CRC16((unsigned char *)text, 4096 * 10);
    msg.data = malloc(sizeof(char) * (sizeof(package) - sizeof(void *) + msg.head.len));
    pack_data(msg.data,&msg,sizeof(package) - sizeof(void *),text,msg.head.len);
    
    printf("send_user len %ld \r\n",sizeof(package) - sizeof(void *) + msg.head.len);
    send_user(key, msg.data, sizeof(package) - sizeof(void *) + msg.head.len);
    free(msg.data);
}

int main(int argc, const char * argv[]) {    
#if 1
	client_info  *table;
	int count;
	int i;
    char sessio[100];
    
	init_config(8898);
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
            send_test_data();
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
    }
#endif

#if 0
    char buff[4];
    buff[0] = 'a';
    buff[1] = 'b';
    buff[2] = 'c';
    buff[3] = 'd';
    
    char *pc;
    
    package *pk = (package*)malloc(sizeof(package));
    pk->head.type = 1;
    pk->head.len = 10;
    pk->fd = 101;
    pk->data = malloc(sizeof(char)*4);
    memcpy(pk->data, "buff", 4);
    
    //pc = (char *)pk->data;
    printf("%ld\r\n",sizeof(*pk));
#endif
	return 0;
}
