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

int list_insert(list_pt  list_head,int num,void *new_data){
    printf("list_insert\n");
    lnode_pt new_node= NULL;
    lnode_pt current=NULL;
    if(list_head==NULL ){
        return -1;
    }
    if(list_head->size!=0){
        new_node=(lnode_pt)malloc(sizeof (lnode_t));
        if(new_node==NULL){
            return -1;
        }
        new_node->data=new_data;
        new_node->prev=new_node->next=NULL;
        if(num>0&&num<=list_head->size){
            current=list_head->head;
            u32 counter=1;
            while (counter<num){
                current=current->next;
                counter++;
            }
            new_node->prev=current;
            current->next=new_node;
            list_head->size++;
        }else{
            free(new_node);
            new_node=NULL;
            return -1;
        }
    }else{
        list_head->head->data=new_data;
        list_head->size++;
    }
    return 0;
}
void list_delete(list_pt list_head,int num){
    printf("list_delete\n");
}
void list_modify(list_pt list_head,int num,void *new_data){
    printf("list_modify\n");
}
int list_search(list_pt list_head,void * find_data,int(*compare)(void*,void*)){
    printf("list_search\n");
    return 0;
}
void list_travel(list_pt list_head){
    printf("list_travel\n");
    u32 counter=list_head->size;
    lnode_pt current=NULL;
    if(counter>0){
        current=list_head->head;
        while (counter>0){
            if(current==NULL){
                printf("list index %d current is NULL \n",list_head->size-counter);
                break;
            }
            ldata_pt data_pt=(ldata_pt)current->data;
            printf("list index %d data id %d data flag %d\n",list_head->size-counter,data_pt->id,data_pt->flag);
            current=current->next;
            counter--;
        }
    }
    printf("list size is %d\n",list_head->size);
}
