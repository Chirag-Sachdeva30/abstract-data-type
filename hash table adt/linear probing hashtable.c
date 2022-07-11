#include <stdio.h>
#include <stdlib.h>

//lets learn how our hashing works in a very simple way.........though hashing functions differ vastly than the discussed hashing function but the general theme is very much same...that is to put numbers in some indexes based on the precomputation on that number.... good hash functions result even in O(N) ammortized complexity


int* hashify(int arr[],int n)
{
    int* hash=(int*)malloc(2*n*sizeof(int)); //we create double size array to have some blank spaces
    for(int i=0;i<2*n;i++)  //intiallize all to zero
        hash[i]=0;

    for(int i=0;i<n;i++)
    {
        int j=arr[i]%(2*n);  //calculate the ideal location for the vertex
        while(hash[j]!=0) //if found already filled,we keep moving
        {
            j=(j+1)%(2*n);
        }
        hash[j]=arr[i];
    }
    return hash;
}
void search(int key, int* hash,int n)
{
    int j=key%(2*n);  //going to the first and ideal candidate to search the key
    for( ;hash[j]!=0;)
    {
        if(hash[j]==key)  //if found return
        {
            printf("found\n");
            break;
        }
        j=(j+1)%(2*n);  //go to the next candidate i.e. the very next index in linear probing
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
    search(58,hash,10);
    search(14,hash,10);
    search(59,hash,10);
    return 0;
}

