#include<bits/stdc++.h>
using namespace std;

void dfs2(int node,int v,vector<vector<int>> &adj,vector<int> &vis)
{
    cout<<node<<" ";
    for(int i=0;i<v;i++)
    {
        if(!vis[i] && adj[node][i])
            {
                vis[i]=1;
                dfs2(i,v,adj,vis);
            }
    }
}
void dfs(int i,int v,stack<int> & st,vector<vector<int>> &adj,vector<int> &vis)
{
    for(int j=0;j<v;j++)
    {
        if(!vis[j] && adj[i][j])
        {
            vis[j]=1;
            dfs(j,v,st,adj,vis);
        }
    }
    st.push(i);
}
void kosaraju(int v, vector<vector<int>> & adj)
{
    cout<<endl;
    //first find the topological sort
    vector<int> vis(v,0);
    stack<int> st;
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            dfs(i,v,st,adj,vis);
        }
    }
    int temp;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<i;j++)
        {
            temp=adj[i][j];
            adj[i][j]=adj[j][i];
            adj[j][i]=temp;
        }
    }
    for(auto & x:vis)
    {
        x=0;
    }
    while(st.size())
    {
        int node=st.top();
        st.pop();
        if(!vis[node])
        {
            vis[node]=1;
            dfs2(node,v,adj,vis);
            cout<<endl;
        }
    }
}
int main()
{
     cout<<"Enter the number of vertices(0 indexed)\n";
    int v;
    cin>>v;
    vector<vector<int>> adj(v,vector<int>(v,0));
    cout<<"Enter the number of edges\n";
    int e;
    cin>>e;
    int a,b;
    for(int i=0;i<e;i++)
    {
        cout<<"Enter from and to vertices of edge "<<i+1<<endl;
        cin>>a>>b;
        adj[a][b]=1;
    }

    kosaraju(v, adj);
    return 0;
}
