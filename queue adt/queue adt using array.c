#include<stdio.h>
#include <stdlib.h>

//Queue ADT

typedef struct
{
    int front;
    int rear;
    int size;
    int *arr;
}queue;


int isempty(queue *q)
{
    return q->front==q->rear?1:0;
}


int isfull(queue *q)
{
     return (q->rear+1)%(q->size+1)==q->front?1:0;
}

void enqueue(queue *q,int x)
{
    if(isfull(q))
    {
        printf("queue overflow\n");
        return;
    }
    else
    {
        q->rear=(q->rear+1)%(q->size+1);
        q->arr[q->rear]=x;
    }
}

int dequeue(queue *q)
{
    if(isempty(q))
    {
        printf("queue underflow\n");
        return -1;
    }
    else
    {
        q->front=(q->front+1)%(q->size+1);
        return(q->arr[q->front]);
    }
}

int queuetop(queue *q)
{
    if(isempty)
    {
        printf("queue underflow\n");
        return -1;
    }
    return q->arr[q->front+1];
}

int peek(queue *q,int index)
{
    if(index>q->size)
    {
        printf("invalid index\n");
        return -1;
    }

    return q->arr[q->front + index];
}

void display(queue *q)
{
    int i=q->rear;
    while(i!=q->front)
    {
        printf("%d ",q->arr[i]);
        i=(i+1)%(q->size+1);
    }
}

//Queue ADT ends

int main()
{
    return 0;
}
