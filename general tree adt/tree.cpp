#include<iostream>
#include<queue>
#include "nodefortree.h"
#include <stack>
#include<cstdint>

using namespace std;


class tree
{
    private:
        node* root;

    public:
        tree()
        {
            queue<node*> q;
            root=new node;
            cout<<"Enter value of root node\n";
            cin>>root->data;
            root->lchild=root->rchild=NULL;
            q.push(root);
            int l, r;
            while(!q.empty())
            {
                node* t=q.front();
                q.pop();
                cout<<"Enter lchild and rchild of node "<<t->data<<endl;
                cin>>l>>r;
                if (l==-1)
                {
                    t->lchild=nullptr;
                }
                else
                {
                    t->lchild= new node;
                    t->lchild->data=l;
                    t->lchild->lchild=t->lchild->rchild=nullptr;
                    q.push(t->lchild);
                }


                   if (r==-1)
                {
                    t->rchild=nullptr;
                }
                else
                {
                    t->rchild= new node;
                    t->rchild->data=r;
                    t->rchild->lchild=t->rchild->rchild=nullptr;
                   q. push(t->rchild);
                }

            }
        }

           void preorder();
           void inorder();
           void postorder();


        ~tree()
            {
                 queue<node*> q;
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

};


void tree::preorder()
{
    stack<node*> st;
    node *t=root;

    while(t!=nullptr ||  !st.empty())
   {
         if(t!=nullptr)
            {
                cout<<t->data<<" ";
                st.push(t);
                t=t->lchild;
            }
            else
            {
                t=st.top()->rchild;
                st.pop();
            }
    }

    cout<<endl;
}



void tree::inorder()
{
    stack<node*> st;
    node *t=root;

    while(t!=nullptr ||  !st.empty())
   {
         if(t!=nullptr)
            {
                st.push(t);
                t=t->lchild;
            }
            else
            {

                t=st.top();
                cout<<t->data<<" ";
                t=t->rchild;
                st.pop();
            }
    }

    cout<<endl;
}



void tree::postorder()
{
    stack<intptr_t> st;
    node *t=root;
    intptr_t x;

    while(t!=nullptr ||  !st.empty())
   {
         if(t!=nullptr)
            {
                st.push((intptr_t)t);
                t=t->lchild;
            }
            else
            {
                 x=st.top();
                st.pop();
                if (x>0)
                {
                    t=(node*)x;
                    st.push(x*(-1));
                    t=t->rchild;
                }
                else
                {
                    t=(node*)(x*(-1));
                    cout<< t->data<<" ";
                    t=nullptr;
                }

            }
    }

    cout<<endl;
}





int main()
{
    tree test;
    test.postorder();
    return 0;
}
