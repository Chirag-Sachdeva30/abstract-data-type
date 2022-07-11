#include <stdio.h>



void Insert(int A[], int start,int gap,int n)
{
    for(int i=start+gap;(i-start)/gap<n;i=i+gap)
    {
        int temp=A[i];
        int j=i-gap;
       while(j>=start && A[j]>temp)
       {
           A[j+gap]=A[j];
           j=j-gap;
       }
       A[j+gap]=temp;
    }

    for(int i=0;i<10;i++)
    printf("%d ",A[i]);
    printf("\n");

}
void ShellSort(int A[],int start,int gap,int n)
{
    if(n<2)
        return;


   ShellSort(A,start,gap*2,(n+1)/2);
   ShellSort(A,start+gap,gap*2,n/2);
   Insert(A,start,gap,n);

}

int main()
{

int A[]={11,13,8,7,12,16,9,24,10,3},n=10,i;
ShellSort(A,0,1,n);
return 0;
}
