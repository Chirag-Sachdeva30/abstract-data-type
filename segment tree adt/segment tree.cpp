
#include<bits/stdc++.h>
using namespace std;

void maketree(int arr[],int ss,int se,int a[],int i)
{
    if(ss==se)
    {
        a[i]=arr[ss];
        return ;
    }
    int mid=(ss+se)/2;
    maketree(arr,ss,mid,a,2*i+1);
    maketree(arr,mid+1,se,a,2*i+2);
    a[i]=a[2*i+1]+a[2*i+2];
}

int rangequery(int a[],int rs,int re,int ss,int se,int i)
{
    int mid=(ss+se)/2;
    if(rs>se || re<ss)
    return 0;
    else if(rs<=ss && re>=se)
        return a[i];

    else return rangequery(a,rs,re,ss,mid,2*i+1)+rangequery(a,rs,re,mid+1,se,2*i+2);
}

void update(int a[],int arr[],int idx,int newval,int ss,int se,int i)
{

    int mid=(ss+se)/2;
    if(idx>se || idx<ss)
    return;
    else if(idx>=ss && idx<=se)
        a[i]=a[i]-arr[idx]+newval;
        if(ss==se)
            return;
        update(a,arr,idx,newval,ss,mid,2*i+1);
         update(a,arr,idx,newval,mid+1,se,2*i+2);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int a[4*n];
    maketree(arr,0,n-1,a,0);
    update(a,arr,0,100,0,n-1,0);
    cout<<rangequery(a,0,3,0,n-1,0);
    return 0;
}
