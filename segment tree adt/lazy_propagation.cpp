#include<bits/stdc++.h>
using namespace std;

class segment_tree
{
    private:
        vector<int> a;
        vector<int> lazy;
        int* arr;
        int n;
        void maketree(int ss,int se,int i)
        {
            if(ss==se)
            {
                a[i]=arr[ss];
                return ;
            }
            int mid=(ss+se)/2;
            maketree(ss,mid,2*i+1);
            maketree(mid+1,se,2*i+2);
            a[i]=a[2*i+1]+a[2*i+2];
        }

    int rangequery(int rs,int re,int ss,int se,int i)
{
    if(lazy[i]!=0)
    {
        a[i]+=(se-ss+1)*lazy[i];
        if(ss!=se)
        {
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }
    int mid=(ss+se)/2;
    if(rs>se || re<ss)
    return 0;
    else if(rs<=ss && re>=se)
        return a[i];

    else return rangequery(rs,re,ss,mid,2*i+1)+rangequery(rs,re,mid+1,se,2*i+2);
}

void updatequerry(int l,int r,int new_val,int ss,int se,int i)
{
    if(lazy[i]!=0)
    {
        a[i]+=(se-ss+1)*lazy[i];
        if(ss!=se)
        {
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }

    if(r<ss || se<l)
    {
        return;
    }
    int mid=(ss+se)/2;
    if(ss>=l && se<=r)
    {
        updatequerry(l,r,new_val,ss,mid,2*i+1);
        updatequerry(l,r,new_val,mid+1,se,2*i+2);
        a[i]=a[2*i+1]+a[2*i+2];
        return;
    }
    a[i]+=(se-ss+1)*new_val;
      if(ss==se)
        {
            return;
        }
    lazy[2*i+1]+=new_val;
    lazy[2*i+2]+=new_val;
}

    public:
    segment_tree(int arr[],int n)
    {
        a.resize(4*n);
        lazy.resize(4*n);
        this->arr=arr;
        this->n=n;
        maketree(0,n-1,0);
    }

    int range(int l,int r)
    {
        return rangequery(l,r,0,n-1,0);
    }
    void update(int l,int r,int new_val)
    {
        updatequerry(l,r,new_val,0,n-1,0);
    }
};





int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    segment_tree st1(arr,n);
    st1.update(0,4,3);
    cout<<st1.range(0,3);
        st1.update(0,3,-3);
    cout<<st1.range(0,3);
    cout<<st1.range(1,4);
    return 0;
}
