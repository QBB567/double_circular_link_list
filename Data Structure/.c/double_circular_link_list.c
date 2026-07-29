#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 1

//˫��ѭ������
//我是djjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj
//jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj
//jjjjjjjjjjjjjj
typedef int DATA_T;//������������
//�������ݽڵ�ṹ��
typedef struct list_node
{
    DATA_T data;
    struct list_node* next;//ǰ��ָ��
    struct list_node* prev;//���ָ��
}Node_t;

//���������ṹ��
typedef struct link_List
{
    int num;//�ڵ�����
    struct list_node* Head;//��¼�׽ڵ��ַ
    struct list_node* Tail;//��¼β�ڵ��ַ
}List_t;

//����������
List_t* double_circular_link_list_creat(void)
{
    //�����������ڴ�
    List_t* list=(List_t*)malloc(1*sizeof(list));
    if(list==NULL)
    {
        printf("list malloc fail\n");
        return NULL;
    }
    //��ʼ������
    list->Head=NULL;
    list->Tail=NULL;
    list->num=0;

    return list;
}

//�������ݽڵ�
Node_t* link_list_node_creat(DATA_T data)
{
    //����ڵ���ڴ�
    Node_t* node=(Node_t*)malloc(1*sizeof(Node_t));
    if(node==NULL)
    {
        printf("node malloc fail\n");
        return NULL;
    }
    //��ʼ���ڵ�
    node->data=data;
    node->next=NULL;
    node->prev=NULL;

    return node;
}

//β������
int link_list_tailinsert(List_t*list,DATA_T data)
{
    //����ڵ�
    Node_t* new_node=link_list_node_creat(data);
    //����ʧ��
    if(new_node==NULL)
    {
        printf("node creat fail\n");
        return 0;
    }
    //�ж��Ƿ�Ϊ������
    if(list->num==0)
    {
        list->Head=new_node;
        list->Tail=new_node;
        new_node->next=list->Head;
    }
    else
    {
        list->Tail->next=new_node;//β�ڵ����һ���ڵ�ָ���½ڵ�
        new_node->prev=list->Tail;//�½ڵ��ǰһ���ڵ�ָ��β�ڵ�
        list->Tail=new_node;//β�ڵ�ָ���½ڵ�
        new_node->next=list->Head;//�½ڵ����һ����ַָ���׽ڵ�
    }
    list->num++;

    return 1;
}

//ͷ������
int link_list_Headinsert(List_t*list,DATA_T data)
{
    //����ڵ�
    Node_t* new_node=link_list_node_creat(data);
    //����ʧ��
    if(new_node==NULL)
    {
        printf("node creat fail\n");
        return 0;
    }
    //�ж��Ƿ�Ϊ������
    //�ձ�����
    if(list->num==0)
    {
        list->Head=new_node;
        list->Tail=new_node;
        new_node->next=list->Head;
    }
    else
    {
        list->Head->prev=new_node;//�׽ڵ�ĺ��ָ��ָ���½ڵ�
        new_node->next=list->Head;//�½ڵ��ǰ��ָ��ָ���׽ڵ�
        list->Head=new_node;//�׽ڵ�ָ���½ڵ�
        list->Tail->next=list->Head;//β�ڵ����һ���ڵ�ָ���׽ڵ�
    }
    list->num++;
    return 1;
}

//ɾ�����ݣ�ͷɾ��βɾ���м�ɾ��
int link_list_DelNode(List_t*list,DATA_T data)
{
    //�ж������Ƿ�Ϊ��
    if(list->num==0)
    {
        printf("list is empty\n");
        return 0;
    }
    //�ҵ�ɾ���ڵ��λ��
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
    //�ж��ҵ���λ�����׽ڵ㻹��β�ڵ�
    //ͷɾ
    if(del_ndoe==list->Head)
    {
       list->Head=del_ndoe->next;
       list->Head->prev=NULL;
       del_ndoe->next=NULL;
       list->Tail->next=list->Head;
    }
    //βɾ
    else if(del_ndoe==list->Tail)
    {
        del_ndoe->prev->next=list->Head;//ɾ���ڵ��ǰһ���ڵ��ǰ��ָ��ָ���׽ڵ�
        list->Tail=del_ndoe->prev;//β�ڵ�ָ��ɾ���ڵ��ǰһ���ڵ�
        del_ndoe->prev=NULL;//ɾ���ڵ�ĺ��ָ��ָ���
    }
    //�м�ɾ��
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

//���ҽڵ�
int link_list_FindNode(List_t*list,DATA_T data)
{
    Node_t*temp=list->Head;
    int i=1;
    //�ж������Ƿ�Ϊ��
    if(list->num==0)
    {
        printf("list is empty\n");
        return 0;
    }
    while (1)
    {
        if(temp->data==data)
        {
            printf("����%d�ڵ�%d��λ��\n",temp->data,i);
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

//�޸�����
int link_list_ChangeNode(List_t*list,DATA_T data,DATA_T change_data)
{
    Node_t*temp=list->Head;
    //�ж������Ƿ�Ϊ��
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

//��ӡ����
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

//˫��ѭ��������������
int ui(List_t* list)
{
    int cmd;//��������
    int val;
    int data;
    while (1)
    {
        printf("--------˫��ѭ������--------\n");
        printf("1.ͷ������\n");
        printf("2.β������\n");
        printf("3.ɾ�����������\n");
        printf("4.�޸�����\n");
        printf("5.��������\n");
        printf("----------------------\n");

        scanf("%d",&cmd);
        switch(cmd)
        {
            //ͷ������
            case 1:
                    scanf("%d",&val);
                    link_list_Headinsert(list,val);
                    link_list_print(list);
                    break;
            //β������
            case 2:
                    scanf("%d",&val);
                    link_list_tailinsert(list,val);
                    link_list_print(list);
                    break;
            //ɾ������
            case 3:
                    scanf("%d",&val);
                    link_list_DelNode(list,val);
                    link_list_print(list);
                    break;
            //�޸�����
            case 4:
                    scanf("%d",&val);
                    scanf("%d",&data);
                    link_list_ChangeNode(list,val,data);
                    link_list_print(list);
                    break;
            //��������
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
    //����������
    List_t* list=double_circular_link_list_creat();
    if(list==NULL)
    {
        printf("list creat fail\n");
    }
    ui(list);

    return 0;
}