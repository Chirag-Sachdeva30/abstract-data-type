#include<bits/stdc++.h>
using namespace std;

void bfs(int v, vector<int> adj[])
{
    vector<int> vis(v,0);
    queue<int> q;
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            q.push(i);
            vis[i]=1;
            while(q.size())
            {
                int node=q.front();
                q.pop();
                cout<<node <<" ";
                for(auto a: adj[node])
                {
                    if(!vis[a])
                    {
                        vis[a]=1;
                        q.push(a);
                    }
                }
            }
        }
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
    cout<<"Bfs of the provided graph is as follows:\n";
    bfs(v, adj);
    return 0;
}
