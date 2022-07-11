#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int parent,vector<int> adj[], vector<int> &vis,vector<int> &dis,vector<int> &low,int &curr)
{
    vector<int> child;
    low[i]=dis[i];
    int count=0;
    for(auto x:adj[i])
    {
        if(x!=parent)
        {
            if(!vis[x])
            {
                count++;

                vis[x]=1;
                dis[x]=++curr;
                dfs(x,i,adj,vis,dis,low,curr);
                low[i]=min(low[x],low[i]);
                if(parent==-1)
                {
                    if(count>1)
                        cout<<i<<" ";
                }
               else if(low[x]>=dis[i])
                    cout<<i<<" ";
            }
              else
                low[i]=min(dis[x],low[i]);

        }
    }

        return;
}

void articulate(int v, vector<int> adj[])
{
    vector<int>dis(v,0);
    vector<int>low(v,INT_MAX);
    vector<int>vis(v,0);
    dis[0]=1;
    low[0]=1;
    vis[0]=1;
    int curr=1;
    dfs(0,-1,adj,vis,dis,low,curr);
    cout<<endl<<"discovery times are"<<endl;
    for(auto x:dis)
        cout<<x<<" ";
    cout<<endl;
    cout<<"low times are"<<endl;
    for(auto x:low)
        cout<<x<<" ";
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
    cout<<"Articulation points are as follows:\n";
    articulate(v, adj);
    return 0;
}

