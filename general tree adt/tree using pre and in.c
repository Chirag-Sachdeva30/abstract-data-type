#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    struct node *lchild;
    struct node *rchild;
    int data;
}node;
node *root=NULL;

int search(int key, int in[],int start,int end)
{
    for(int i=start;i<=end;i++)
    {
        if(in[i]==key)
            return i;
    }
    return -1;
}

node* createpre(int start, int end,int pre[],int in[])
{
    if(start>end)
       return NULL;

    static int i=0;
    node *t;

        t=(node*)malloc(sizeof(node));
        t->data=pre[i++];
        t->lchild=t->rchild=NULL;

    int pos;
        pos=search(t->data,in,start,end);

       t->lchild=createpre(start,pos-1,pre,in);
       t->rchild=createpre(pos+1,end,pre,in);
        return t;
}


node* createpost(int start, int end,int post[],int in[])
{
    if(start>end)
       return NULL;

    static int i=8; // caution this 8 is variable based on the fact that what is the size of postarray you are sending ...to make it universal,send one more data through input that is size of post or in
    node *t;

        t=(node*)malloc(sizeof(node));
        t->data=post[i--];
        t->lchild=t->rchild=NULL;
    int pos;
        pos=search(t->data,in,start,end);
       t->rchild=createpost(pos+1,end,post,in);
       t->lchild=createpost(start,pos-1,post,in);
        return t;
}



void display(node *todisplay)
{
        if(todisplay==NULL)
        {
            return;
        }
        else
        {
            display(todisplay->lchild);
            printf("%d ",todisplay->data);
            display(todisplay->rchild);
            return;
        }

}

int main()
{
  int in[9]={1,3,4,7,5,12,15,8,6};
  int pre[9]={5,1,4,3,7,15,12,6,8};
  int post[9]={3,7,4,1,12,8,6,15,5};
  root=createpre(0,8,pre,in);
  display(root);
  printf("/n");
  root=createpost(0,8,post,in);
  display(root);
  return 0;
}
