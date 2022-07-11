#include <stdio.h>
#include <stdlib.h>
//this is quadratic probing...an improvement over the linear probing technique

int* hashify(int arr[],int n)
{
    int* hash=(int*)malloc(2*n*sizeof(int));
    for(int i=0;i<2*n;i++)
        hash[i]=0;

    for(int i=0;i<n;i++)
    {
        int j=arr[i]%(2*n),k=1;
        while(hash[j]!=0)
        {
            j=(j+k*k)%(2*n);
            k++;
        }
        hash[j]=arr[i];
    }
    return hash;
}
void search(int key, int* hash,int n)
{
    int j=key%(2*n);
    for(int k=1 ;hash[j]!=0;k++)
    {
        if(hash[j]==key)
        {
            printf("found\n");
            break;
        }
        j=(j+k*k)%(2*n);
    }
         if(hash[j]==0)
            printf("not found\n");
}

int main()
{
    int arr[10]={12,65,78,90,96,58,76,45,41,60};
    int *hash;
    hash=hashify(arr,10);
    search(12,hash,10);
    search(200,hash,10);
    search(76,hash,10);
    search(59,hash,10);
    return 0;
}
