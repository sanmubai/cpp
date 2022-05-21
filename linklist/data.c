//
// Created by baibin on 5/22/22.
//

#include "../include/data.h"
static ldata_t newData={
        .id=0,
        .flag=0,
        .Init=init_data_func,


};

u32 init_data_func(){
    return 0;
}

void init_data(list_pt ptlist){
    list_insert(&ptlist,1,&newData);
}