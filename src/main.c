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

	return 0;
}
