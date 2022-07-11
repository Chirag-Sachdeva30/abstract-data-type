#include<bits/stdc++.h>
using namespace std;

void bfs(int v, vector<int> adj[])
{
    vector<int> vis(v,0);
    vector<int> dis(v,INT_MAX);
    queue<int> q;

            q.push(0);
            dis[0]=0;
            vis[0]=1;
            while(q.size())
            {
                int node=q.front();
                q.pop();
                for(auto a: adj[node])
                {
                    if(!vis[a])
                    {
                        vis[a]=1;
                        dis[a]=dis[node]+1;
                        q.push(a);
                    }
                }
            }
        for(auto a: dis)
            cout<<a<<" ";
        return ;
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
        adj[a].push_back(b);;
        adj[b].push_back(a);
    }

    //till here we have recieved all the input from the user;
    //now we will run bfs on the input;
    cout<<"Bfs of the provided graph is as follows:\n";
    bfs(v, adj);
    return 0;
}

