#include<bits/stdc++.h>
using namespace std;

bool bfs(int v, vector<int> adj[])
{
    vector<int> col(v,0);
    queue<int> q;
    for(int i=0;i<v;i++)
    {
        if(!col[i])
        {
            q.push(i);
            col[i]=1;
            while(q.size())
            {
                int node=q.front();
                q.pop();

                for(auto a: adj[node])
                {
                    if(!col[a])
                    {
                        col[a]=-1*col[node];
                        q.push(a);
                    }
                    else if(col[a]==col[node])
                        return false;
                }
            }
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

    if(bfs(v, adj))
    cout<<"yes we can!\n";
    else
        cout<<"No you cant\n";
    return 0;
}

