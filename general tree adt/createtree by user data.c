#include <stdio.h>
#include <stdlib.h>

//we need to make a tree, so for a tree we must define its node

typedef struct node
{
    struct node *leftchild;
    struct node *rightchild;
    int data;
}node;

//we will also require a queue while creating the tree to store the addresses of nodes

typedef struct queue
{
    int size;
    int front;
    int rear;
    node **s;
}queue;

//we should define create, enqueue and dequeue to make our queue functional

void create(queue*q, int x)
{
    q->size=x+1;
    q->s=(node**)malloc(q->size*(sizeof(node*)));
    q->front=q->rear=0;
}

void enqueue(queue *q,node* x)
{
    if((q->rear+1)%q->size==q->front)
        printf("queue is full\n");
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->s[q->rear]=x;
    }
}

 node* dequeue(queue *q)
 {
     if(q->front==q->rear)
     {
         printf("queue is empty\n");
         return NULL;
     }
     else
     {
         q->front++;
         return q->s[q->front];
     }
 }


 //we will also need a function create tree, which will take the inputs of tree from the user only and store them

 void createtree(node **root,queue *q)
 {
     int x;
     printf("Enter your root node\n");
     scanf(" %d",&x);
     *root=(node*)malloc(sizeof(node));
     (*root)->data=x;
     (*root)->leftchild=(*root)->rightchild=NULL;
     enqueue(q,*root);
     node *t,*p;
     while(q->front!=q->rear)
     {
         t=dequeue(q);
         printf("Enter the value of leftchild of %d\n",t->data);
         p=(node*)malloc(sizeof (node));
         scanf(" %d",&(p->data));
         if(p->data==-1)
         {
             t->leftchild=NULL;
             free(p);
         }
         else
         {
             p->leftchild=p->rightchild=NULL;
            t->leftchild=p;
            enqueue(q,p);
         }


         printf("Enter the value of rightchild of %d\n",t->data);
         p=(node*)malloc(sizeof (node));
         scanf(" %d",&(p->data));
         if(p->data==-1)
         {
             t->rightchild=NULL;
             free(p);
         }
         else
         {
            p->leftchild=p->rightchild=NULL;
            t->rightchild=p;
            enqueue(q,p);
         }

     }
 }
 //we will also be printing the contents of our tree
void preorder(node *root)
 {

     if(root==NULL)
        return;

         printf("%d ",root->data);
        preorder(root->leftchild);
        preorder(root->rightchild);

 }

 void inorder(node *root)
 {

     if(root==NULL)
        return;

         inorder(root->leftchild);
         printf("%d ",root->data);
         inorder(root->rightchild);

 }


 void postorder(node *root)
 {

     if(root==NULL)
        return;

         postorder(root->leftchild);
         postorder(root->rightchild);
         printf("%d ",root->data);
 }



 void levelorder(node *root,queue *q)
 {
     if(root==NULL)
    {
        printf("Tree is empty\n");
        return;
    }

     printf("%d ",root->data);
      if(root->leftchild!=NULL)
            enqueue(q,root->leftchild);

          if(root->rightchild!=NULL)
            enqueue(q,root->rightchild);
     node *t;
     while(q->front!=q->rear)
     {
         t=dequeue(q);
         printf("%d ",t->data);
         if(t->leftchild!=NULL)
            enqueue(q,t->leftchild);

          if(t->rightchild!=NULL)
            enqueue(q,t->rightchild);
    }



 }

 int main()
 {
     queue q;
     node *root;
     printf("please tell what size of queue will be sufficient for your tree\n");
     int n;
     scanf(" %d",&n);
     create(&q,n);
     printf("please enter your tree\n");
     createtree(&root,&q);
     printf("Your tree is as follows\n");
     preorder(root);
     printf("\n");
     inorder(root);
     printf("\n");
     postorder(root);
     printf("\n");
     levelorder(root,&q);
     return 0;
 }
