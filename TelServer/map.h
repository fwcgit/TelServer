//
//  map.h
//  TelServer
//
//  Created by fwc on 2018/5/24.
//  Copyright © 2018年 fwc. All rights reserved.
//

#ifndef map_h
#define map_h
#include "list.h"
typedef struct hashmap
{
    List *keyMap;
    List *map;
    size_t size;
}hashMap;

void init_map(hashMap *hm);
void free_map(hashMap *hm);
void put_map(hashMap *map,char *key,void *data);
void remove_map(hashMap *map,char *key);
unsigned char has_map(hashMap *map,char *key);
void* get_map(hashMap *map,char *key);
void log_map(hashMap *map,char *key);
#endif /* map_h */
