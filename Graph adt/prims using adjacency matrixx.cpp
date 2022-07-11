#include<bits/stdc++.h>
using namespace std;

int prims(int v, vector<vector<int>> &adj)
{
   vector<int> dis(v,INT_MAX);
   dis[0]=0;
   int curr=0,next,total=0;
   int mn;
   for(int i=0;i<v-1;i++)
   {
       mn=INT_MAX;

       for(int i=0;i<v;i++)
            {
                if(dis[i])
                {
                    if(adj[curr][i]!=INT_MAX)
                    dis[i]=min(dis[i],adj[curr][i]);

                        if(dis[i]<mn)
                       {
                           next=i;
                           mn=dis[i];
                       }
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
    vector<vector<int>> adj(v,vector<int>(v,INT_MAX));
    cout<<"Enter the number of edges\n";
    int e;
    cin>>e;
    int a,b,c;
    for(int i=0;i<e;i++)
    {
        cout<<"Enter from and to vertices of edge "<<i+1<<endl;
        cin>>a>>b>>c;
        adj[a][b]=c;
        adj[b][a]=c;
    }

    cout<<prims(v, adj);
    return 0;
}
