#include <stdio.h>
#include <stdlib.h>

//定义数据类型
typedef int DATA_T;

//定义队列结构体
typedef struct queue
{
    DATA_T* data;//队列首地址
    int front;   //队首下标
    int rear;    //队尾下标
    int size;    //最大容量
}queue_t;

//创建空队列
queue_t*queue_creat(int size)
{
    //申请队列堆内存
    queue_t* queue=(queue_t*)malloc(1*sizeof(queue_t));
    if(queue==NULL)
    {
        printf("queue malloc fail\n");
        return NULL;
    }
    //初始化空队列
    queue->size=size;
    queue->front=0;
    queue->rear=0;
    //申请队列节点堆内存
    queue->data=(DATA_T*)malloc(size*sizeof(DATA_T));
    if(queue->data==NULL)
    {
        printf("data malloc fail\n");
        free(queue);
        return NULL;
    }

    return queue;
}

//入队--尾插
int queue_enqueue(queue_t*queue,DATA_T data)
{
    //判断队列是否满
    if( (queue->rear+1)%(queue->size)==queue->front )
    {
        printf("queue is full\n");
        return 0;
    }
    queue->data[queue->rear]=data;//将数据赋值给队尾
    queue->rear=(queue->rear+1)%(queue->size);//更新队尾的下标

}


//出队--头删
int queue_dequeue(queue_t*queue)
{
    DATA_T data_t;
    //判断队列是否为空
    if(queue->front==queue->rear)
    {
        printf("queue is empty\n");
        return -1;
    }
    data_t=queue->data[queue->front];
    queue->front=(queue->front+1)%(queue->size);
    return data_t;
}

//打印队列
void queue_print(queue_t*queue)
{
    int temp=queue->front;
    while(temp!=queue->rear)
    {
        printf("%d\t",queue->data[temp]);
        temp=(temp+1)%(queue->size);
    }
    printf("\n");
}
int main()
{
    queue_t* queue=queue_creat(10);

    queue_enqueue(queue,10);
    queue_enqueue(queue,20);
    queue_enqueue(queue,30);
    queue_enqueue(queue,40);

    printf("dataPOP=%d\n",queue_dequeue(queue));
    printf("dataPOP=%d\n",queue_dequeue(queue));
    printf("dataPOP=%d\n",queue_dequeue(queue));
    printf("dataPOP=%d\n",queue_dequeue(queue));
    printf("dataPOP=%d\n",queue_dequeue(queue));

    queue_print(queue);
    
    return 0;
}