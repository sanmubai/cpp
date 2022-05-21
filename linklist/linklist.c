//
// Created by baibin on 5/19/22.
//
#include "../include/linklist.h"

list_pt create(){
    printf("create!\n");
    list_pt list_head=NULL;
    list_head=(list_pt)malloc(sizeof(list_t));
    if(list_head==NULL){
        return NULL;
    }
    list_head->size=0;
    list_head->head= (lnode_pt)malloc(sizeof (lnode_t));
    if(list_head->head==NULL){
        return NULL;
    }
    list_head->head->next=list_head->head->prev=NULL;
    list_head->head->data=NULL;
    list_head->tail=list_head->head;
    return list_head;
}

int list_insert(list_t ** list_head,int num,void *new_data){
    printf("list_insert");
    return 0;
}
void list_delete(list_t ** list_head,int num){
    printf("list_delete");
}
void list_modify(list_t ** list_head,int num,void *new_data){
    printf("list_modify");
}
int list_search(list_t ** list_head,void * find_data,int(*compare)(void*,void*)){
    printf("list_search");
    return 0;
}
void list_travel(list_t ** list_head){

}
