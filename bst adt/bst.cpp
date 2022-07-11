#include <iostream>
#include<stack>
#include <queue>
#include "nodefortree.h"

using namespace std;


class bst
{
    private:
        node *root;
        int height(node* p);
        int lsuc(node *t);
        int rsuc(node *t);
    public:

        bst();
        void insert(int x);
        node* search(int x);
        node* rsearch(int x, bool y=1);
        node* rinsert(int x, node* t=nullptr, bool y=1);
        node* Delete(int x, node* t=nullptr,bool y=1);
        void createpre(int* pre, int n);
        ~bst();

};

 inline bst::bst()
        {
            root=nullptr;
        }


void bst::insert(int x)
        {
            node *ptr = new node;
            ptr->data=x;
            ptr->lchild = ptr->rchild = nullptr;

            if(root==nullptr)
            {
                root=ptr;
                return;
            }
            node* t=root;
            while(1)
            {
                if(t->data==x)
                return;

                else if (t->data>x  && t->lchild!=nullptr)
                {
                    t=t->lchild;
                }
                else if(t->data<x  && t->rchild!=nullptr)
                {
                    t=t->rchild;
                }
                else break;
            }
            if(t->data>x)
                t->lchild=ptr;
            else
                t->rchild=ptr;
        }






    node* bst::rinsert(int x,node *t,bool y)
        {

           if(y==1)
            t=root;

            if(t==nullptr)
            {
                 node *ptr = new node;
                ptr->data=x;
                ptr->lchild = ptr->rchild = nullptr;

                 if(root==nullptr)
                    root=ptr;

                return ptr;
            }
            if(t->data==x)
                    return t;


            if (t->data>x)
                {
                    t->lchild=rinsert(x,t->lchild,0);
                }
                else if(t->data<x)
                {
                     t->rchild=rinsert(x,t->rchild,0);
                }
                return t;
        }

        node* bst::search(int x)
        {
            node *t=root;
            while(t!=nullptr)
            {
                if(t->data==x)
                    return t;
                else if(t->data>x)
                {
                    t=t->lchild;
                }
                    else
                        t=t->rchild;
            }
            return nullptr;
        }


         node* bst::rsearch(int x,bool y)
        {
            static node *t;

            if(y==1)
            t=root;

            if(t!=nullptr)
            {
                if(t->data==x)
                    return t;
                else if(t->data>x)
                {
                    t=t->lchild;
                    return rsearch(x,0);
                }
                    else
                        t=t->rchild;
                    return rsearch(x,0);
            }
            else return nullptr;
        }

            void bst::createpre(int* pre, int n)
            {
                root=new node;
                root->data=pre[0];
                root->lchild=root->rchild=nullptr;
                stack<node*> st;
                int i=1;
                node *t=root,*p;
                while(i<n)
                {
                        if(pre[i]<t->data)
                        {
                            p=new node;
                            p->data=pre[i];
                            p->lchild=root->rchild=nullptr;
                            t->lchild=p;
                            st.push(t);
                            t=t->lchild;
                            i++;
                        }
                        else if (pre[i]>t->data)
                        {
                            if(pre[i]<st.top()->data)
                            {
                            p=new node;
                            p->data=pre[i];
                            p->lchild=root->rchild=nullptr;
                            t->rchild=p;
                            t=t->rchild;
                            i++;
                            }
                            else
                            {
                                t=st.top();
                                st.pop();
                            }
                        }
                }
            }

         bst::~bst()

            {
                 queue<node*> q;
                 if(root)
                q.push(root);
                node* t;
                while(!q.empty())
                {
                     t=q.front();
                     q.pop();


                if (t->lchild!=nullptr)
                    q.push(t->lchild);

                  if (t->rchild!=nullptr)
                    q.push(t->rchild);

                delete t;
                }
            }

            int  bst::height(node* t)
            {
                if (t==nullptr)
                    return 0;
                return height(t->lchild)>height(t->rchild)?height(t->lchild)+1:height(t->rchild)+1;
            }

            int bst::lsuc(node *t)
            {
                node *p=t->lchild;
                while(p->rchild!=nullptr)
                {
                    p=p->rchild;
                }
                return p->data;
            }

            int bst::rsuc(node *t)
            {
                node *p=t->rchild;
                while(p->lchild!=nullptr)
                {
                    p=p->lchild;
                }
                return p->data;
            }



            node* bst::Delete(int x, node* t,bool y)
            {
                if(y==1)
                    t=root;

                    if(t==nullptr)
                            return t;


                if(x>t->data)
                {
                    t->rchild=Delete(x,t->rchild,0);
                }

                else if(x<t->data)
                {
                    t->lchild=Delete(x,t->lchild,0);
                }

                else
                {
                    if(t->lchild==nullptr && t->rchild==nullptr)
                    {
                            if(t==root)
                            root=nullptr;
                        delete t;
                        t=nullptr;
                        return t;
                    }

                    if(height(t->lchild)>height(t->rchild))
                    {
                        int z=lsuc(t);
                         t->data=z;
                        t->lchild=Delete(z,t->lchild,0);
                    }
                    else
                    {
                        int z=rsuc(t);
                         t->data=z;
                        t->rchild=Delete(z,t->rchild,0);
                    }
                }
                return t;
            }


int main()
{

         bst test;

        test.Delete(45);
    return 0;
}
