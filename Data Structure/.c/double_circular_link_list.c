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

//创建空链表
List_t* double_circular_link_list_creat(void)
{
    //申请链表堆内存
    List_t* list=(List_t*)malloc(1*sizeof(list));
    if(list==NULL)
    {
        printf("list malloc fail\n");
        return NULL;
    }
    //初始化链表
    list->Head=NULL;
    list->Tail=NULL;
    list->num=0;

    return list;
}

//创建数据节点
Node_t* link_list_node_creat(DATA_T data)
{
    //申请节点堆内存
    Node_t* node=(Node_t*)malloc(1*sizeof(Node_t));
    if(node==NULL)
    {
        printf("node malloc fail\n");
        return NULL;
    }
    //初始化节点
    node->data=data;
    node->next=NULL;
    node->prev=NULL;

    return node;
}

//尾插数据
int link_list_tailinsert(List_t*list,DATA_T data)
{
    //申请节点
    Node_t* new_node=link_list_node_creat(data);
    //申请失败
    if(new_node==NULL)
    {
        printf("node creat fail\n");
        return 0;
    }
    //判断是否为空链表
    if(list->num==0)
    {
        list->Head=new_node;
        list->Tail=new_node;
        new_node->next=list->Head;
    }
    else
    {
        list->Tail->next=new_node;//尾节点的下一个节点指向新节点
        new_node->prev=list->Tail;//新节点的前一个节点指向尾节点
        list->Tail=new_node;//尾节点指向新节点
        new_node->next=list->Head;//新节点的下一个地址指向首节点
    }
    list->num++;

    return 1;
}

//头插数据
int link_list_Headinsert(List_t*list,DATA_T data)
{
    //申请节点
    Node_t* new_node=link_list_node_creat(data);
    //申请失败
    if(new_node==NULL)
    {
        printf("node creat fail\n");
        return 0;
    }
    //判断是否为空链表
    //空表插入
    if(list->num==0)
    {
        list->Head=new_node;
        list->Tail=new_node;
        new_node->next=list->Head;
    }
    else
    {
        list->Head->prev=new_node;//首节点的后继指针指向新节点
        new_node->next=list->Head;//新节点的前驱指针指向首节点
        list->Head=new_node;//首节点指向新节点
        list->Tail->next=list->Head;//尾节点的下一个节点指向首节点
    }
    list->num++;
    return 1;
}

//删除数据，头删，尾删，中间删除
int link_list_DelNode(List_t*list,DATA_T data)
{
    //判断链表是否为空
    if(list->num==0)
    {
        printf("list is empty\n");
        return 0;
    }
    //找到删除节点的位置
    Node_t*del_ndoe=list->Head;
    while (1)
    {
        if(del_ndoe->data==data)
        {
            break;
        }
        del_ndoe=del_ndoe->next;
        if(del_ndoe==list->Head)
        {
            printf("no find node\n");
            return 0;
        }
    }
    //判断找到的位置是首节点还是尾节点
    //头删
    if(del_ndoe==list->Head)
    {
       list->Head=del_ndoe->next;
       list->Head->prev=NULL;
       del_ndoe->next=NULL;
       list->Tail->next=list->Head;
    }
    //尾删
    else if(del_ndoe==list->Tail)
    {
        del_ndoe->prev->next=list->Head;//删除节点的前一个节点的前驱指针指向首节点
        list->Tail=del_ndoe->prev;//尾节点指向删除节点的前一个节点
        del_ndoe->prev=NULL;//删除节点的后继指针指向空
    }
    //中间删除
    else
    {
        del_ndoe->prev->next=del_ndoe->next;
        del_ndoe->prev=NULL;
        del_ndoe->next=NULL;
    }
    list->num--;
    free(del_ndoe);
    return 1;
    
}

//查找节点
int link_list_FindNode(List_t*list,DATA_T data)
{
    Node_t*temp=list->Head;
    int i=1;
    //判断链表是否为空
    if(list->num==0)
    {
        printf("list is empty\n");
        return 0;
    }
    while (1)
    {
        if(temp->data==data)
        {
            printf("数据%d在第%d个位置\n",temp->data,i);
            return 1;
        }
        temp=temp->next;
        i++;
        if(temp==list->Head)
        break;
    }
    printf("no find node\n");
    return 0;
}

//修改数据
int link_list_ChangeNode(List_t*list,DATA_T data,DATA_T change_data)
{
    Node_t*temp=list->Head;
    //判断链表是否为空
    if(list->num==0)
    {
        printf("list is empty\n");
        return 0;
    }
    while(1)
    {
        if(temp->data==data)
        {
            temp->data=change_data;
            return 1;
        }
        temp=temp->next;
        if(temp==list->Head)
        break;
    }
    printf("no find node\n");
    return 0;
}

//打印链表
int link_list_print(List_t*list)
{
    if(list->num==0)
    {
        return 0;
    }
    Node_t* temp=list->Head;
    while(1)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
        if(temp==list->Head)
        break;
    }
    printf("\n");
}

//双向循环链表操作界面
int ui(List_t* list)
{
    int cmd;//输入命令
    int val;
    int data;
    while (1)
    {
        printf("--------双向循环链表--------\n");
        printf("1.头插数据\n");
        printf("2.尾插数据\n");
        printf("3.删除输入的数据\n");
        printf("4.修改数据\n");
        printf("5.查找数据\n");
        printf("----------------------\n");

        scanf("%d",&cmd);
        switch(cmd)
        {
            //头插数据
            case 1:
                    scanf("%d",&val);
                    link_list_Headinsert(list,val);
                    link_list_print(list);
                    break;
            //尾插数据
            case 2:
                    scanf("%d",&val);
                    link_list_tailinsert(list,val);
                    link_list_print(list);
                    break;
            //删除数据
            case 3:
                    scanf("%d",&val);
                    link_list_DelNode(list,val);
                    link_list_print(list);
                    break;
            //修改数据
            case 4:
                    scanf("%d",&val);
                    scanf("%d",&data);
                    link_list_ChangeNode(list,val,data);
                    link_list_print(list);
                    break;
            //查找数据
            case 5:
                    scanf("%d",&val);
                    link_list_FindNode(list,val);
                    break;
            default:
            return 0;
        }
    }
}


int main()
{
    //创建空链表
    List_t* list=double_circular_link_list_creat();
    if(list==NULL)
    {
        printf("list creat fail\n");
    }
    ui(list);

    return 0;
}