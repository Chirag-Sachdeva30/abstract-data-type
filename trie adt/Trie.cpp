#include<bits/stdc++.h>
using namespace std;



    struct trienode
{
    trienode* child[26];
    bool isend;
    trienode()
    {
        for(int i=0;i<26;i++)
            child[i]=nullptr;
            isend=false;
    }
};


class trie
{
    private:
    trienode* root;
    public:
    trie()
    {
        root=new trienode();
    }
    void Insert(string a)
    {
        trienode* temp=root;
        for(int i=0;i<a.size();i++)
        {
            int x=a[i]-'a';
            if(temp->child[x])
            {
                temp=temp->child[x];
            }
            else
            {
                temp->child[x]=new trienode();
                temp=temp->child[x];
            }
        }
        temp->isend=true;
        return;
    }

    bool Search(string a)
    {
                trienode* temp=root;
        for(int i=0;i<a.size();i++)
        {
            int x=a[i]-'a';
            if(temp->child[x])
            {
                temp=temp->child[x];
            }
            else
            {
                return false;
            }
        }
        if(temp->isend)
        return true;
        return false;
    }

    bool isempty(trienode* root)
    {
        if(root->isend)return false;
        for(int i=0;i<26;i++)
        {
            if(root->child[i])return false;
        }return true;
    }
    trienode* helper (string a,trienode* root,int i)
    {
        if(root==nullptr)
            return nullptr;
            if(i==a.size())
            {
                root->isend=false;
                if(isempty(root))
                {
                    delete root;
                    root= nullptr;
                }
                return root;
            }

            int x=a[i]-'a';
            root->child[x]=helper(a,root->child[x],i+1);
            if(isempty(root))
            {
                delete(root);
                root=nullptr;
            }
                return root;
    }

      void Delete(string a)
    {
        root=helper(a,root,0);
    }

};

int main()
{
    trie a;
}
