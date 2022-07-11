#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;
node *count[10];


void insert(int key,int index)
{
    if(count[index]==NULL)
    {
        node *p=(node *)malloc(sizeof(node));

            p->data=key;
            p->next=NULL;
            count[index]=p;
            return;
    }

    node *t=count[index];

    while(t->next != NULL)
    {

        t=t->next;
    }
    node *p=(node *)malloc(sizeof(node));

    p->data=key;
    p->next=NULL;
    t->next=p;

}
void refill(int A[],int n)
{
    int i=0,k=0;
    while(i<10)
    {
        if(count[i]==NULL)
            {
                i++;
                continue;
            }


        if(count[i]->next==NULL)
        {
            A[k++]=count[i]->data;
            free(count[i]);
            count[i]=NULL;
        }
        else
        {
             A[k++]=count[i]->data;
             node *t=count[i];
            count[i]=count[i]->next;
            free(t);
            t=NULL;
        }
    }
}
void radixsort(int A[],int n)
{

    for(int i=1;i<=1000;i*=10)
    {
        for(int j=0;j<n;j++)
            insert(A[j],(A[j]/i)%10);
            refill(A,n);

    }
}


int main()
{

int A[]={111,233,348,567,182,616,9,24,410,1003},n=10;

for(int i=0;i<10;i++)
    count[i]=NULL;

radixsort(A,n);

for(int i=0;i<n;i++)
    printf("%d ",A[i]);
return 0;
}
