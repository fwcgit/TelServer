//
//  list.h
//  TelServer
//
//  Created by fwc on 2018/5/24.
//  Copyright © 2018年 fwc. All rights reserved.
//

#ifndef list_h
#define list_h
#include<stdio.h>
#include<stdlib.h>

typedef struct listNode
{
    void *data;
    void *next;
    char key[32];
}ListNode;

typedef struct list
{
    ListNode *first;
    ListNode *last;
    int count;
    size_t size;
}List;

typedef void (*add)(List *list,void *data,int index);

List * init_list(size_t size);
void add_list_index(List *list,void *data,int index);
void add_list(List *list,void *data);
void* get_list(List *list,int index);
void* poll_list(List *list);
void remove_list(List *list,int index);
#endif /* list_h */
