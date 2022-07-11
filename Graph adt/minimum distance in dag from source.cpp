#include<bits/stdc++.h>
using namespace std;

void dfs(stack<int> &st, int i,vector<pair<int,int>> adj[],vector<int> &vis)
{
    vis[i]=1;
    for(auto x:adj[i])
    {
        if(!vis[x.first])
        {
            dfs(st,x.first,adj,vis);
        }
    }
    st.push(i);
}

void topodfs(vector<pair<int,int>> adj[],int v)
{

    vector<int> vis(v,0);
    stack<int> st;
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
            dfs(st,i,adj,vis);
    }

    vector<int> dis(v,INT_MAX);
    dis[0]=0;
    while(st.size())
    {
        int node=st.top();
        st.pop();
        if(dis[node]!=INT_MAX)
        {
            for(auto x:adj[node])
            {
                if(dis[x.first]>dis[node]+x.second)
                    dis[x.first]=dis[node]+x.second;
            }
        }
    }
    for(auto x:dis)
        cout<<x<<" ";

}
int main()
{
    int v;
    cin>>v;
    vector<pair<int,int>> adj[v];
    int e;
    cin>>e;

    int a,b,w;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
    }


    topodfs(adj,v);

}
