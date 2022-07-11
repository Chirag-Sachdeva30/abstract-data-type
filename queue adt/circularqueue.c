#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int front;
    int rear;
    int size;
    int *q;
}queue;
queue Q;


void enqueue(int n)
{

    if((Q.rear+1)%(Q.size+1)==Q.front)
    printf("Queue is full\n");
    else
    {
        Q.rear=(Q.rear+1)%(Q.size+1);
        Q.q[Q.rear]=n;
    }
}

int dequeue()
{
    if (Q.front==Q.rear)
{

        printf("Queue is empty\n");
        return -1;
}
    else
    {
        Q.front=(Q.front+1)%(Q.size+1);
        return Q.q[Q.front];
    }
}

display()
{
    int i=Q.front;
    while(i!=Q.rear)
    {
        i=((i+1)%(Q.size+1));
        printf("%d ",Q.q[i]);
    }
}

int main()
{
    Q.front=Q.rear=0;
    printf("Enter the size of your queue\n");
    scanf(" %d",&Q.size);
    Q.q=(int*)malloc((Q.size+1)*sizeof(int));
enqueue(50);
display();
printf("\n");
enqueue(70);
display();
printf("\n");
enqueue(80);
display();
printf("\n");
enqueue(90);
display();
printf("\n");
enqueue(100);
display();
printf("\n");
enqueue(110);
display();
printf("\n");
dequeue();
display();
printf("\n");
dequeue();
display();
printf("\n");
enqueue(15);
display();
printf("\n");
dequeue();
display();
printf("\n");
enqueue(20);
display();
printf("\n");
dequeue();
display();
printf("\n");
dequeue();
display();
printf("\n");
dequeue();
display();
printf("\n");
dequeue();
display();
printf("\n");
dequeue();
display();
printf("\n");
dequeue();
display();
printf("\n");
dequeue();
display();
printf("\n");
enqueue(11);
display();
printf("\n");
enqueue (25);
display();
printf("\n");
dequeue();
display();
printf("\n");


}
