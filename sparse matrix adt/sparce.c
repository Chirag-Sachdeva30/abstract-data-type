#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int cor_i;
    int cor_j;
    int val;
}element;

typedef struct
{
    int n;
    int m;
    int num;
    element *e;
}sparce;

void feed (sparce *given)
{
    for(int k=0;k<(given->num);k++)
    {
        printf("Enter row, column and value of element %d\n",k+1);
        scanf(" %d %d %d",&given->e[k].cor_i,&given->e[k].cor_j,&given
                                                                        ->e[k].val);
                         given->e[k].cor_j-=1;
                         given->e[k].cor_i-=1;

    }
}

void print(sparce given)
{
    printf("\n");
    int curr=0;
    for(int a=0;a<given.n;a++)
    {
        for(int b=0;b<given.m;b++)
        {
            if(curr<given.num)
            {
                if(a<given.e[curr].cor_i)
                    printf("0 ");

                else if(b<given.e[curr].cor_j)
                    printf("0 ");
                else
                    printf("%d ",given.e[curr++].val);

            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}

sparce add(sparce mtx1,sparce mtx2)
{
    printf("the sum of matrices is\n");
    sparce mtx3;
    mtx3.n=mtx1.n;
    mtx3.m=mtx1.m;
    int i=0;
    int j=0;
    int k=0;
    mtx3.num=mtx1.num+mtx2.num;
    mtx3.e=(element*)malloc(mtx3.num*sizeof(element));
    while(i<mtx1.num && j<mtx2.num)
    {
        if(mtx1.e[i].cor_i > mtx2.e[j].cor_i)
        mtx3.e[k++]=mtx2.e[j++];
    else if(mtx1.e[i].cor_i < mtx2.e[j].cor_i)
        mtx3.e[k++]=mtx1.e[i++];
    else if(mtx1.e[i].cor_j < mtx2.e[j].cor_j)
        mtx3.e[k++]=mtx1.e[i++];
        else if(mtx1.e[i].cor_j > mtx2.e[j].cor_j)
        mtx3.e[k++]=mtx2.e[j++];
    else
    {
        mtx3.e[k]=mtx2.e[j++];
        mtx3.e[k++].val+=mtx1.e[i++].val;
    }
    }
    while(i<mtx1.num)
    {
        mtx3.e[k++]=mtx1.e[i++];
    }
    while(j<mtx2.num)
    {
        mtx3.e[k++]=mtx2.e[j++];
    }
    mtx3.num=k;
    return mtx3;
}

int main()
{
    sparce sample[3];
    int row,column,elem;
    for(int i=0;i<2;i++)
    {
        printf(" Enter the values of row,columns,and elements of your matrix %d\n",i+1);
    scanf(" %d %d %d",&row,&column,&elem);
    sample[i].n=row;
    sample[i].m=column;
    sample[i].num=elem;
    sample[i].e=(element*)malloc(elem*sizeof(element));
    feed(&sample[i]);
    print(sample[i]);
    }
    if(sample[0].n==sample[1].n && sample[0].m==sample[1].m)
    {
        sample[2]=add(sample[0],sample[1]);
        print(sample[2]);
    }
    else printf("these 2 matrices can not be added\n");
    for(int i=0;i<3;i++)
    {
        free(sample[i].e);
        sample[i].e=NULL;
    }
    return 0;
}
