//
//  map.c
//  TelServer
//
//  Created by fwc on 2018/5/24.
//  Copyright © 2018年 fwc. All rights reserved.
//

#include "map.h"
#include "list.h"
#include <string.h>
#include "server.h"

unsigned int hashCode(char *key)
{
    unsigned int code =0;
    
    while(*key != '\0')
    {
        code = code + *key++;
    }
    
    return code * 31;
}

void init_map(hashMap *hm)
{
    hm->map = (List*)malloc(sizeof(List)*(hm->size));
    hm->map->size = hm->size;
    hm->map->count = 0;
    hm->keyMap = init_list(hm->size * hm->size);
    memset(hm->map, 0, sizeof(List) * hm->size );
}

void free_map(hashMap *hm)
{
    free(hm);
}

void put_map(hashMap *hw,char *key,void *data)
{
    unsigned int hashcode = hashCode(key);
    int index = hashcode % hw->size;
    
    if((hw->map+index)->count == 0)
    {
        ListNode *node = (ListNode*)malloc(sizeof(ListNode));
        node->data = data;
        strcpy(node->key, key);
        node->next = NULL;
        
        (hw->map+index)->first = node;
        (hw->map+index)->count = 1;
    }
    else
    {
    
        
		int i;
		ListNode *node = (ListNode*)malloc(sizeof(ListNode));
        node->data = data;
        strcpy(node->key, key);
        node->next = NULL;
        
        ListNode *pn =hw->map[index].first;
        if(NULL != pn)
        {
            for(i = 0; i < hw->map[index].count-1;i++)
            {
                pn = pn->next;
            }
            node->next = pn->next;
            pn->next = node;
            
            hw->map[index].count++;
        }

    }
    
}

void remove_map(hashMap *hw,char *key)
{
    unsigned int hashcode = hashCode(key);
    int index = hashcode % hw->size;
    
    if((hw->map+index)->count > 0)
    {
    
        if((hw->map+index)->count == 1)
        {
            memset((hw->map+index), 0, sizeof(List));
        }
        else
        {
            ListNode *pn =(hw->map+index)->first;
            while(pn->next != NULL)
            {
                if(strcmp(pn->key, key) == 0)
                {
                    
                    if(pn->next != NULL)
                    {
                        pn->data = ((ListNode*)pn->next)->data;
                        strcpy(pn->key, ((ListNode*)pn->next)->key);
                        pn = pn->next;
                        
                    }
                    else
                    {
                        memset(pn->key, 0, sizeof(pn->key));
                        pn = NULL;
                        (hw->map+index)->count--;
                    }
                    
                    break;
                }
                
                 pn = pn->next;
            }
        }
        
    }
}

unsigned char has_map(hashMap *hw,char *key)
{
    unsigned int hashcode = hashCode(key);
    int index = hashcode % hw->size;
    
    return (hw->map+index)->count > 0;
}

void* get_map(hashMap *hw,char *key)
{
    unsigned int hashcode = hashCode(key);
    int index = hashcode % hw->size;
    
    if((hw->map+index)->count == 1)
    {
        return (hw->map+index)->first;
    }
    else if((hw->map+index)->count > 0)
    {
        ListNode *pn =(hw->map+index)->first;
        
        while(pn->next != NULL)
        {
            if(strcmp(pn->key,key) == 0)
            {
                return pn;
            }
                
            pn = pn->next;
        }
        
    }
    
    return NULL;
}

void log_map(hashMap *hw,char *key)
{
}
