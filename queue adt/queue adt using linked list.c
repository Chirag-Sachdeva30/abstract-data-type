#include<stdio.h>
#include <stdlib.h>

//Queue ADT

typedef struct queue
{
    int data;
    struct queue *next;
}queue;
queue *front=NULL;
queue *rear=NULL;


int isempty()
{
    return rear==NULL?1:0;
}


int isfull()
{
    queue *t=(queue*)malloc(sizeof(queue));
     return t==NULL?1:0;
}

void enqueue(int x)
{
    if(isfull())
    {
        printf("queue overflow\n");
        return;
    }
    else if(isempty())
    {
        queue *t=(queue*)malloc(sizeof(queue));
        t->next=NULL;
        t->data=x;
        front=rear=t;
    }
    else
        {
        queue *t=(queue*)malloc(sizeof(queue));
        t->next=NULL;
        t->data=x;
        rear->next=t;
        rear=t;
    }
}

int dequeue()
{
    if(isempty())
    {
        printf("queue underflow\n");
        return -1;
    }
    else
    {
        queue *todelete=front;
        front=front->next;
        int x=todelete->data;
        free(todelete);
        todelete=NULL;
        return(x);
    }
}

int queuetop()
{
    if(isempty())
    {
        printf("queue underflow\n");
        return -1;
    }
    return front->data;
}

int peek(int index)
{
    queue *t=front;
    for(int i=0;i<index-1 && t!=NULL ;i++)
        t=t->next;
    if(t==NULL)
    {
        printf("invalid index\n");
        return -1;
    }
    return t->data;
}

void display()
{

   queue *t=front;
    while(t!=NULL)
        {
            printf("%d ",t->data);
            t=t->next;
        }
}

//Queue ADT ends

int main()
{
    return 0;
}
