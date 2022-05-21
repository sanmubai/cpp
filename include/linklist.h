//
// Created by baibin on 5/19/22.
//

#ifndef CPP_LINKLIST_H
#define CPP_LINKLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct data{
    u8 id;
    u8 flag;
    u8 *send_buffer;
    u32 (* Init)(void);
    int (* SendFunc)(void);
} ldata_t;
typedef ldata_t* ldata_pt;

typedef struct lnode{
    void * data;
    struct lnode * next;
    struct lnode * prev;
}lnode_t;
typedef lnode_t * lnode_pt;

typedef struct list{
    u32 size;
    lnode_pt head;
    lnode_pt tail;
}list_t;
typedef list_t * list_pt;

list_pt create(void);
int list_insert(list_t ** list_head,int num,void *new_data);
void list_delete(list_t ** list_head,int num);
void list_modify(list_t ** list_head,int num,void *new_data);
int list_search(list_t ** list_head,void * find_data,int(*compare)(void*,void*));
void list_travel(list_t ** list_head);
#endif //CPP_LINKLIST_H
