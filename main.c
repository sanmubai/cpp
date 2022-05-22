#include "include/linklist.h"
#include "include/data.h"

int main() {
    list_pt ptlist = create();
    init_data(ptlist);
    list_travel(ptlist);
    return 0;
}

