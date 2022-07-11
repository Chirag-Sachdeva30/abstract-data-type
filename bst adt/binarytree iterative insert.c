#include <stdio.h>
#include <stdlib.h>

//we need to make a tree, so for a tree we must define its node

typedef struct node
{
    struct node *leftchild;
    struct node *rightchild;
    int data;
}node;

 //we will also need a function insert which will take the inputs of tree from the user and store them

 void insert(node **t,int key) //as we are not returning anything, we are taking the storage for the head pointer by its address as intially we do not have any node so we will manually create one node in heap and put its address in the head storage waiting for it in the stack
 {
     node *root=*t;
    if(*t==NULL)
    {
        (*t)=(node*)malloc(sizeof(node));
        (*t)->data=key;
        (*t)->leftchild=(*t)->rightchild=NULL;
    }
    else
    {
        while(1)
    {
        if(root->data>key && root->leftchild!=NULL)
        root=root->leftchild;
        else if(root->data<key && root->rightchild!=NULL)
        root=root->rightchild;
        else break;
    }
        node *p=(node*)malloc(sizeof(node));
        p->data=key;
        p->leftchild=p->rightchild=NULL;
        if(key<root->data)
            root->leftchild=p;
        else
            root->rightchild=p;
     }
 }
 //we will also be printing the contents of our tree
void display(node *root)
 {
     if(root==NULL)
        return;
        display(root->leftchild);
        printf("%d ",root->data);
        display(root->rightchild);
 }

 int main()
 {
     node *root=NULL;
     insert(&root,10);
     insert(&root,40);
     insert(&root,30);
     insert(&root,15);
     insert(&root,33);
     insert(&root,9);
     printf("Your tree is as follows\n");
     display(root);
     return 0;
 }

