#include<bits/stdc++.h>
using namespace std;

bool dfs(int i,  vector<int>&col, vector<int> adj[])
{
    for(auto x:adj[i])
    {
        if(!col[x])
        {
            col[x]=-1*col[i];
            if(!dfs(x,col,adj))
            return false;
        }
        else if (col[x]==col[i])
            return false;
    }
    return true;
}
bool dfsofgraph(int v, vector<int> adj[])
{
    vector<int>col(v,0);
    for(int i=0;i<v;i++)
    {
        if(!col[i])
        {
            col[i]=1;
           if(!dfs(i,col,adj))
           return false;
        }
    }
    return true;
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

    if(dfsofgraph(v, adj))
        cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}

