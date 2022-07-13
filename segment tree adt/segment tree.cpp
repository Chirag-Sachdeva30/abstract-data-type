#include<bits/stdc++.h>
using namespace std;

class segment_tree
{
    private:
        vector<int> a;
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
    int mid=(ss+se)/2;
    if(rs>se || re<ss)
    return 0;
    else if(rs<=ss && re>=se)
        return a[i];

    else return rangequery(rs,re,ss,mid,2*i+1)+rangequery(rs,re,mid+1,se,2*i+2);
}

void updatequerry(int idx,int ss,int se,int i)
{

    int mid=(ss+se)/2;
      if(ss==se)
        {
            a[i]=arr[ss];
            return;
        }
    if(idx<=mid)
    updatequerry(idx,ss,mid,2*i+1);
    else
    updatequerry(idx,mid+1,se,2*i+2);
    a[i]=a[2*i+1]+a[2*i+2];
}

    public:
    segment_tree(int arr[],int n)
    {
        a.resize(4*n);
        this->arr=arr;
        this->n=n;
        maketree(0,n-1,0);
    }

    int range(int l,int r)
    {
        return rangequery(l,r,0,n-1,0);
    }
    void update(int i,int newval)
    {
        arr[i]=newval;
        updatequerry(i,0,n-1,0);
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
    st1.update(0,100);
    cout<<st1.range(0,3);
    return 0;
}
