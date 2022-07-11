#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node*right;
    Node(int x)
    {
        data=x;
        left=right=nullptr;
    }
};

Node* maketree(int arr[],int x)
{
    queue<pair<Node*,pair<int,int>>> q;
    int idx=0;
    Node *root=new Node(arr[idx]);
    q.push({arr[i],{INT_MIN,INT_MAX}});
    while(idx<x)
    {
            Node* temp=q.front().first;
            int lower=q.front().second.first;
            int upper=q.front().second.second;
            if(arr[idx]<temp->data  && arr[idx]>lower)
            {
                Node *newNode=new Node(arr[idx++]);
                temp->left=newNode;
                q.push({newNode,{lower,temp->data});
            }

                if(idx==x)
                        return root;

            if(arr[idx]>temp->data  && arr[idx]<upper)
            {
                Node *newNode=new Node(arr[idx++]);
                temp->right=newNode;
                q.push({newNode,{temp->data,upper});
            }

            q.pop();
    }
    return root;
}

int main()
{
    int x;
    cin>>x;
    int arr[x];
    for(int i=0;i<x;i++)
        cin>>arr[i];

       Node* root= maketree(arr,x);

       return;

}
