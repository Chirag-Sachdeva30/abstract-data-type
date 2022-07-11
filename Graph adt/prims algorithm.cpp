#include<bits/stdc++.h>
using namespace std;

int prims(int v, vector<pair<int,int>> adj[])
{
   vector<int> dis(v,INT_MAX);
   dis[0]=0;
   int curr=0,next,total=0;
   int mn;
   for(int i=0;i<v-1;i++)
   {
       mn=INT_MAX;
       for(auto x:adj[curr])
       {
           if(dis[x.first])
           {
               dis[x.first]=min(dis[x.first],x.second);
           }
       }
       for(int i=0;i<v;i++)
            {
                if(dis[i] && dis[i]<mn)
               {
                   next=i;
                   mn=dis[i];
               }
           }
                dis[next]=0;
                total+=mn;

             curr=next;
   }
   return total;
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

    cout<<prims(v, adj);
    return 0;
}
