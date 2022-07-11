#include<bits/stdc++.h>
using namespace std;

void dfs(int i,  vector<int>&vis, vector<int> adj[])
{
    for(auto x:adj[i])
    {
        if(!vis[x])
        {
            vis[x]=1;
            dfs(x,vis,adj);
        }
    }
}
int dfsofgraph(int v, vector<int> adj[])
{
    vector<int> vis(v,0);
    int count=0;
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            count++;
            vis[i]=1;
           dfs(i,vis,adj);
        }
    }
return count;
}
int main()
{
    cout<<"Enter the number of vertices(0 indexed)\n";
    int v;
    cin>>v;
    vector<int> adj[v];
    cout<<"Enter the number of edges\n";
    int e;
    cin>>e;
    int a,b;
    for(int i=0;i<e;i++)
    {
        cout<<"Enter from and to vertices of edge "<<i+1<<endl;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //till here we have recieved all the input from the user;
    //now we will run bfs on the input;
    cout<<"number of components are "<<dfsofgraph(v, adj)<<endl;
    return 0;
}

