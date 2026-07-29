#ifndef MY_HEAD_H
#define MY_HEAD_H

#include <stdio.h>
#include <stdlib.h>

//双向循环链表

typedef int DATA_T;//定义数据类型
//创建数据节点结构体
typedef struct list_node
{
    DATA_T data;
    struct list_node* next;//前驱指针
    struct list_node* prev;//后继指针
}Node_t;

//创建链表结构体
typedef struct link_List
{
    int num;//节点数量
    struct list_node* Head;//记录首节点地址
    struct list_node* Tail;//记录尾节点地址
}List_t;

List_t* double_circular_link_list_creat(void);//创建空链表
Node_t* link_list_node_creat(DATA_T data);//创建数据节点
int link_list_tailinsert(List_t*list,DATA_T data);//尾插数据
int link_list_Headinsert(List_t*list,DATA_T data);//头插数据
int link_list_DelNode(List_t*list,DATA_T data);//删除数据，头删，尾删，中间删除
int link_list_FindNode(List_t*list,DATA_T data);//查找节点
int link_list_ChangeNode(List_t*list,DATA_T data,DATA_T change_data);//修改数据
int link_list_print(List_t*list);//打印链表
int ui(List_t* list);//双向循环链表操作界面

#endif