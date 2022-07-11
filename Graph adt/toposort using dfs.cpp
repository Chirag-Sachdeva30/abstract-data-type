#include<bits/stdc++.h>
using namespace std;

void dfs(int i,stack<int>&st,  vector<int>&vis, vector<int> adj[])
{
    for(auto x:adj[i])
    {
        if(!vis[x])
        {
            vis[x]=1;
            dfs(x,st,vis,adj);
        }
    }
    st.push(i);
}
void dfsofgraph(int v, vector<int> adj[])
{
    vector<int> vis(v,0);
    stack<int> st;
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
           dfs(i,st,vis,adj);
        }
    }
    while(st.size())
    {
        cout<<st.top()<<" ";
        st.pop();
    }

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
    //now we will run bfs on the input;
    cout<<"toposort of the provided graph is as follows:\n";
    dfsofgraph(v, adj);
    return 0;
}
