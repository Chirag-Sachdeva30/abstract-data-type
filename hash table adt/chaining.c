#include <stdio.h>
#include <stdlib.h>
//lets learn chaining ...one of the good hashing techniques when the content is evenly spread out

typedef struct node
{
    int data;
    struct node *next;
}node;

node** hashify(int arr[],int n)
{
    node **hash=(node**)malloc(n*sizeof(node*));
    for(int i=0;i<n;i++)
        hash[i]=NULL;

    for(int i=0;i<n;i++)
    {
        int j=(arr[i]%n);
        if(hash[j]==NULL)  //there has been no node yet in our hash of j..hence we enter its first node
        {
            node *p=(node*)malloc(sizeof(node));
            p->data=arr[i];
            p->next=NULL;
            hash[j]=p;
        }
        else if(arr[i]<hash[j]->data)  // here the root has to be changed so we handle this case seperately
        {
            node *p=(node*)malloc(sizeof(node));
            p->data=arr[i];
            p->next=hash[j];
            hash[j]=p;
        }
        else //putting the new value in the sorted position in the current hash
        {
            node *k=hash[j];
            while(k->next && k->next->data<arr[i])
                k=k->next;
             node *p=(node*)malloc(sizeof(node));
            p->data=arr[i];
            p->next=k->next;
            k->next=p;
        }
    }
    return hash;
}

void search(int key,node **hash,int n)
{
    int j=(key%10);
    node*k=hash[j];
    while(k && k->data!=key)
        k=k->next;

    if(k)
        printf("found\n");
    else
        printf("not found\n");
}
int main()
{
      int arr[10]={12,65,78,90,96,58,76,45,41,60};
    node **hash;
    hash=hashify(arr,10);
    search(12,hash,10);
    search(45,hash,10);
    search(41,hash,10);
    search(60,hash,10);
    return 0;
}
