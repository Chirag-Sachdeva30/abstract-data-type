#include<bits/stdc++.h>
using namespace std;

void dijikstra(int v,vector<pair<int,int>> adj[])
{
    vector<int> inc(v,0);
    vector<int> dis(v,INT_MAX);
    dis[0]=0;
    inc[0]=1;
    int curr=0,mn;
    for(int i=0;i<v-1;i++)
    {
        for(auto x:adj[curr])
            dis[x.first]=min(dis[x.first],dis[curr]+x.second);

        mn=INT_MAX;
            for(int i=0;i<v;i++)
            {
                if(!inc[i])
                {
                    if(dis[i]<mn)
                    {
                        mn=dis[i];
                        curr=i;
                    }
                }
            }
            inc[curr]=1;
    }
    for(auto x:dis)
    cout<<x<<" ";
    return;
}

int main()
{
    cout<<"Enter the number of vertices(0 indexed)\n";
    int v;
    cin>>v;
    vector<pair<int,int>> adj[v];
    cout<<"Enter the number of edges\n";
    int e;
    cin>>e;
    int a,b,c;
    for(int i=0;i<e;i++)
    {
        cout<<"Enter from and to vertices of edge "<<i+1<<endl;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    dijikstra(v, adj);
    return 0;
}
