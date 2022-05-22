//
// Created by baibin on 5/22/22.
//

#include "../include/data.h"

u32 init_data_func(){
    return 0;
}

void init_data(list_pt ptlist){
    for(int i=0;i<10;i++){
        ldata_pt data_pt=NULL;
        data_pt= (ldata_pt)malloc(sizeof (ldata_t));
        if(data_pt==NULL){
            continue;
        }
        data_pt->id=i;
        data_pt->flag=i;
        data_pt->Init=init_data_func;
        list_insert(ptlist,i,data_pt);
    }
}