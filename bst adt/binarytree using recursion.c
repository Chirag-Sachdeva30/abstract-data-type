#include <stdio.h>
#include <stdlib.h>


//writing the node definition
typedef struct node
{
    struct node *lchild;
    struct node *rchild;
    int data;
}node;
node *root=NULL;

//a useful stack
typedef struct stack
{
    int top;
    node *arr[20];
}stack;
stack st={-1,{0}};


//when we push an element, we increase the top and put node t in the top slot note that here i am not considering if stack is full but that can be dealt with ease
void push(node *t)
{
    st.top++;
    st.arr[st.top]=t;
}
//we pop the element,note that i assume the user knows that the slot must not be empty when he pop so i skip on considering the stack empty case, but that can be dealt with ease
node* pop()
{
    node*t = st.arr[st.top];
    st.top--;
    return t;
}
//peek function
int stacktop()
{
    if(st.top==-1)
        return -1;
    int t=st.arr[st.top]->data;
    return t;
}

//insert the node and return the updated tree
node* insert(node* root,int key)
{
    if(root==NULL)
    {
        node *newnode=(node*)malloc(sizeof(node));
        newnode->data=key;
        newnode->rchild = newnode->lchild = NULL;
        return(newnode);
    }
    else
    {
        if(key > root->data)
        {
            root->rchild=insert(root->rchild,key);
            return root;
        }
        else if(key < root->data)
        {
            root->lchild=insert(root->lchild,key);
            return root;
        }
        else
            return root;
    }
}

//a simple function to calculate the height
int height(node* p)
{
    if(p==NULL)
        return 0;
    int l=height(p->lchild);
    int r=height(p->rchild);
    return (l<r?l+1:r+1);
}

//predecessor
node* prev(node *root)
{
    root=root->lchild;
    while(root->rchild!=NULL)
    {
        root=root->rchild;
    }
    return root;
}

//successor
node* next(node *root)
{
    root=root->rchild;
    while(root->lchild!=NULL)
    {
        root=root->lchild;
    }
    return root;
}
//a function to remove the given key
node* Remove(node *root, int key)
{
    if(root==NULL)
        return root;
    if(key < root->data)
    {
        root->lchild=Remove(root->lchild,key);
        return root;
    }
    else if(key > root->data)
    {
        root->rchild=Remove(root->rchild,key);
        return root;
    }
    else
    {
        if(root->lchild==NULL && root->rchild==NULL)
        {
            free(root);
            return NULL;
        }
    root->data=(height(root->lchild)>=height(root->rchild))?prev(root)->data:next(root)->data;

    if(height(root->lchild)>=height(root->rchild))
        root->lchild=Remove(root->lchild,prev(root)->data);

    else
        root->rchild=Remove(root->rchild,next(root)->data);
    return root;
    }
}
// this is a new function which we didnt touch in avl tree so we will understand it properly
void createtree(int pre[],int n)
{
    int i=0;

    //in case we have no node, we create a new node and assign it to root
    if(root==NULL)
        {
            root=(node*)malloc(sizeof(node));
            root->data=pre[i++];
            root->lchild=root->rchild=NULL;
        }
        node *t=root; //we just make a dummy node
        node *p;
    while(i<n)
    {

       if(t->data > pre[i]) //here we create a newnode and assign it to current root's left, note that before moving to the left, we are putting the node in the stack so that we can come back to it later when we have to fill in the right tree
        {
            p=(node*)malloc(sizeof(node));
            p->data=pre[i++];
            p->lchild=p->rchild=NULL;
            t->lchild=p;
            push(t);
            t=t->lchild;
        }

        else if(t->data==pre[i])
            i++;

        else  if(st.top==-1 || stacktop()>pre[i]) //we have to go to the currents root right only...there are no worries
        {

                p=(node*)malloc(sizeof(node));
                p->data=pre[i++];
                p->lchild=p->rchild=NULL;
                t->rchild=p;
                t=t->rchild;
        }
        else //we have to return to the previous root, as going on curr's right is invalid
        t=pop();

    }
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
    int arr[7]={7,3,4,2,9,1,6};
    createtree(arr,7);
    root=insert(root,31);
    insert(root,12);
    insert(root,5);
    display(root);
    printf("\n");
    Remove(root,15);
    Remove(root,1);
    Remove(root,12);
    Remove(root,14);
    display(root);

    return 0;
}
