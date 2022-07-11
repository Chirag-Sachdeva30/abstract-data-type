#include<bits/stdc++.h>
using namespace std;

bool bfs(int v, vector<int> adj[])
{
    vector<int> indeg(v,0);

    for(int i=0;i<v;i++)
        {
            for(auto x:adj[i])
            indeg[x]++;
        }
    int count=0;
    queue<int> q;

            for(int i=0;i<v;i++)
            {
                if(indeg[i]==0)
                    q.push(i);
            }

            while(q.size())
            {
                count++;
                int node=q.front();
                q.pop();
                for(auto a: adj[node])
                {
                        indeg[a]--;
                        if(indeg[a]==0)
                        q.push(a);
                }
            }
            return count!=v;
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
    if(bfs(v, adj))
        cout<<"Yes there is a cycle\n";
    else
        cout<<"No, aint no cycle in here\n";
    return 0;
}
