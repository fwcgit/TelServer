//
//  list.c
//  TelServer
//
//  Created by fwc on 2018/5/24.
//  Copyright © 2018年 fwc. All rights reserved.
//

#include "list.h"

void insert_list(List *list,void *data,int index)
{
    int i = 0;
    
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    node->next = NULL;
    
    ListNode *pn = list->first;
    for(i = 0 ; i < index-1 ;i++)
    {
        pn = pn->next;
    }
    
    if(NULL != pn)
    {
        node->next = pn->next;
        pn->next = node;
        
        (list->count)++;
    }
}

void insert_list_count(List *list,void *data)
{
    int i = 0;
    
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    node->next = NULL;
    
    if(list->count == 0)
    {
        list->first = node;
    }
    else
    {
        ListNode *pn = list->first;
        for(i = 0 ; i < list->count-1 ;i++)
        {
            pn = pn->next;
        }
        if(NULL != pn)
        {
            node->next = pn->next;
            pn->next = node;
        }
        
    }
    
     (list->count)++;
}



void inseart_first(List *list,void *data)
{
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    node->next = list->first;
    list->first = node;
    
    (list->count)++;
}


List * init_list(size_t size)
{
    List *list  = (List *)malloc(sizeof(List));
    list->first = NULL;
    list->last  = NULL;
    list->count = 0;
    list->size = size;
    
    return list;
}

void add_list_index(List *list,void *data,int index)
{
    if(list->count >= list->size)
    {
        printf("list full ! \r");
        return;
    }
    
    if(index == 0)
    {
        inseart_first(list,data);
        return;
    }
    
    if(index == list->count)
    {
        insert_list_count(list,data);
        return;
    }
    
    insert_list(list,data,index);
    
}

void add_list(List *list,void *data)
{
    insert_list_count(list,data);
}

void* get_list(List *list,int index)
{
    int i = 0;
    
    if(list->count == 0) return NULL;
    
    if(index == 0)
    {
        return list->first;
    }
    
    ListNode *node = list->first;
    
    for(i = 0; i < index;i++)
    {
        node = node->next;
        
        if(i == index-1)
        {
            return node;
        }
    }
    return NULL;
}

void* poll_list(List *list)
{
    ListNode *node = list->first;
    if(node == NULL) return (void*)NULL;
    
    list->first = node->next;
    list->count--;
    
    return node;
}



void remove_list(List *list,int index)
{
    int i = 0;
    ListNode *node = list->first;
    
    if(list->count <= 0) return;
    
    if(index == 0)
    {
        if(list->count == 1)
        {
            free(list->first->data);
            list->first = NULL;
        }
        else
        {
            list->first = node->next;
        }

    }
    else
    {
        for(i = 0 ; i < index -1 ; i++)
        {
            node = node->next;
        }
        free(((ListNode *)node->next)->data);
        node->next = ((ListNode *)node->next)->next;
    }
    
     list->count--;
}
