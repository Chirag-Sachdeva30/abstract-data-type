

//implementation of avl tree where we will insert delete and traverse the tree
//the main property of this tree is that it is a self balancing tree and it maintains its balance on random insertion and deletion

#include <stdio.h>
#include <stdlib.h>

//in each node we want to store its left child its right child ,its data as well as the height of the tree below it

typedef struct node{
    struct node *lchild;
    struct node *rchild;
    int height;
    int data;
}node;
node *root=NULL;

//a standard function to return the height of a tree
int hgt(node *root){
    int x,y;
    if(root==NULL)
        return 0;
    x=hgt(root->lchild);
    y=hgt(root->rchild);
    return x>y?x+1:y+1;
}

//return the difference in the heights of the left and the right child...does this keeping in mind the sign
int Balance (node *t){
    if (t==NULL)
        return 0;
 return(hgt(t->lchild)-hgt(t->rchild));
}

//we need this rotation in case of +2 balance of the current node and +1 balance of the left child
node* LLrotation(node *t){
    node*p=t->lchild;
    t->lchild=p->rchild;
    p->rchild=t;
    return p;
}

//we need this rotation in case of -2 balance of the current node and -1 balance of the right child
node* RRrotation(node *t){
    node*p=t->rchild;
    t->rchild=p->lchild;
    p->lchild=t;
    return p;
}

//we need this rotation in case of -2 balance of the current node and +1 balance of the left child
node* LRrotation(node *t){
node*tl=t->lchild;
node*tlr=tl->rchild;
tl->rchild=tlr->lchild;
t->lchild=tlr->rchild;
tlr->lchild=tl;
tlr->rchild=t;
return tlr;
}

//we need this rotation in case of +2 balance of the current node and -1 balance of the right child
node* RLrotation(node *t){
node*tr=t->rchild;
node*trl=tr->lchild;
tr->lchild=trl->rchild;
t->rchild=trl->lchild;
trl->rchild=tr;
trl->lchild=t;
return trl;
}

// this is a function to insert a node with value x to the avl tree
node* insert(node *t,int x){
    if(t==NULL) // if we have no head,the new node itself will be the head
        {
            node *p=(node*)malloc(sizeof(node)); //creating a new node
            p->lchild=NULL;
            p->rchild=NULL;
            p->data=x;
            p->height=1; //initially the subtree below the node will be empty so the height will be 1
            return p;
        }

    if(x < t->data) //we need to insert the node in the left child so we will call recursively on the left child
        {
           t->lchild=insert(t->lchild,x);
           t->height=hgt(t); //updating the height after adding the node
        }

    if(x > t->data) //similar execution in case of right child
        {
           t->rchild=insert(t->rchild,x);
           t->height=hgt(t);
        }
        //after we have inserted and come back, we want to balance, note that the subtrees have already been balanced in the recursive call

        if(Balance(t)==2 && Balance(t->lchild)==1)
           t= LLrotation(t);

        else if(Balance(t)==2 && Balance(t->lchild)==-1)
            t=LRrotation(t);

        else if(Balance(t)==-2 && Balance(t->rchild)==1)
            t=RLrotation(t);

        else if(Balance(t)==-2 && Balance(t->rchild)==-1)
         t= RRrotation(t);


    return t;
}


void display(node *todisplay){
        if(todisplay==NULL)
        {
            return;
        }
        else
        {
            printf("%d ",todisplay->data);
            display(todisplay->lchild);
            display(todisplay->rchild);
            return;
        }
}

//this is a function to find the successor of our root, this is used when we delete some entry
node* next(node *root)
{
    root=root->rchild;
    while(root->lchild!=NULL)
    {
        root=root->lchild;
    }
    return root;
}

//this is a function to find the predecessor of our root
node* prev(node *root)
{
    root=root->lchild;
    while(root->rchild!=NULL)
    {
        root=root->rchild;
    }
    return root;
}


node* Remove(node *root, int key) //function to remove a node from the avl tree
{
    if(root==NULL) //nothing to do here as we dont find the key
        return root;

    if(key < root->data)//recursively call the left child
        root->lchild=Remove(root->lchild,key);

    if(key > root->data)//recursively call the right child
        root->rchild=Remove(root->rchild,key);

    if(key==root->data)
       {
            if(root->lchild==NULL && root->rchild==NULL) //we are at the leaf, safely delete
                    {
                        free(root);
                        return NULL;
                    }
                    //else, we see if we have more imbalanced left subtree or right subtree, and choose our              successor/predecessor to replace the root accordingly

                    int hl=hgt(root->lchild);
                    int hr=hgt(root->rchild);
                    if(hl>=hr)
                    {
                        root->data=prev(root)->data;
                        root->lchild=Remove(root->lchild,root->data);
                    }
                    else
                    {
                        root->data=next(root)->data;
                        root->rchild=Remove(root->rchild,root->data);
                    }
        }
        //now account for the balancing as it might be disturbed due to rotation
           if(Balance(root)==2 && (Balance(root->lchild)==1 || Balance(root->lchild)==0))
           root= LLrotation(root);

        else if(Balance(root)==2 && Balance(root->lchild)==-1)
            root=LRrotation(root);

        else if(Balance(root)==-2 && (Balance(root->rchild)==1|| Balance(root->lchild)==0))
            root=RLrotation(root);

        else if(Balance(root)==-2 && Balance(root->rchild)==-1)
         root= RRrotation(root);
    return root;

}


    int main()
    {

    //you may call insert and delete on our avl tree..and print its data
        root=insert(root,70);
        root=insert(root,90);
        root=insert(root,80);
        root=insert(root,40);
        root=insert(root,50);
        root=insert(root,60);
        root=insert(root,20);
        root=insert(root,30);
        root=insert(root,10);
        root=Remove(root,90);

        display(root);
        return 0;
    }
