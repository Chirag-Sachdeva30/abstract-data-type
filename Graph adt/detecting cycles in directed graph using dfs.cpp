#include<bits/stdc++.h>
using namespace std;

bool dfs(int i, vector<int> &currpath, vector<int>&vis, vector<int> adj[])
{
    for(auto x:adj[i])
    {
        if(!vis[x])
        {
            vis[x]=1;
            currpath[x]=1;
            if(dfs(x,currpath,vis,adj))
                return true;
        }
        else if (currpath[x])
            return true;
    }
    currpath[i]=0;
    return false;
}
 bool dfsofgraph(int v, vector<int> adj[])
{
    vector<int> vis(v,0);
    vector<int>currpath(v,0);
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            currpath[i]=1;
            vis[i]=1;
           if(dfs(i,vis,currpath,adj))
            return true;
        }
    }
            return false;
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
    }

    //till here we have recieved all the input from the user;
    //now we will run dfs on the input;
    if(dfsofgraph(v, adj))
    cout<<"Yes there is a cycle\n";
    else cout<<"No there aint no cycle\n";
    return 0;
}

