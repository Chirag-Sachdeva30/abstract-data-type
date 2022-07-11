#include <stdio.h>
//this is heap, one of the most useful data structures one may come accross...but implementing a heap is not so simple,lets dive straight into it


//to implement heap data structure, the biggest idea is that we dont actually need a data structure as such.
//we can just need the array passed to us and throught the concepts of heap,we can convert it to heap, hence all what we need to keep is the length of the heap,thats all,here we initialise our heap size by 1
int l=1;

void insert(int a[],int t)
{
    for(int b=1;b<=t;b++)
    {
        int i=b;
        int temp=a[i];
    while(i>1)
    {
        if(temp>a[i/2])
        {
            a[i]=a[i/2];
            i=i/2;
        }
        else
            break;
    }
    a[i]=temp;
    }
    l=t;
}


void heapify(int a[],int n)
{

   int i,j;
   for(int index=n/2;index>0;index--)
    {
        i=index;
        j=2*i;
           while(j<=n)
       {
           if (j<n && a[j+1]>a[j])
            j=j+1;

            if(a[i]>a[j])
            break;

            else
            {
                 int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                i=j;
                j=2*j;
            }
       }
    }
    l=n;
}

int Delete(int a[])
{
    int x=a[1];
    a[1]=a[l];
    l--;
    int i=1;
    int j=2;
    while(j<=l)
    {
        if(j<l && a[j+1]>a[j])
            j=j+1;
        if(a[j]>a[i])
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i=j;
            j=2*j;
        }
        else break;
    }
    a[l+1]=x;
    return x;
}
void display(int a[])
{

    for(int i=1;i<=l;i++)
        printf("%d ",a[i]);
}

void sortify(a)
{
        for(int i=l;i>0;i--)
        Delete(a);
}

void heapsort(int a[], int n)
{
    heapify(a,n);
    sortify(a);
        for(int i=1;i<=7;i++)
         printf("%d ",a[i]);

}

int main()
{
    int a[8]={0,5,8,6,2,4,1,9};

     insert(a,7);
     display(a);
      printf("\n");

}

