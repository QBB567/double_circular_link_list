#include "my_head.h"

int main()
{
    //´´½¨¿ÕÁ´±í
    List_t* list=double_circular_link_list_creat();
    if(list==NULL)
    {
        printf("list creat fail\n");
    }
    ui(list);

    return 0;
}