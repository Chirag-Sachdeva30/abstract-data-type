#include<bits/stdc++.h>
using namespace std;

void bford(int v,int e, vector<vector<int>> &edge)
{
    vector<int>dis(v,INT_MAX);
    dis[0]=0;
    for(int i=0;i<v-1;i++)
    {
        for(auto x:edge)
        {
            if(dis[x[1]]>dis[x[0]]+x[2])
                dis[x[1]]=dis[x[0]]+x[2];
        }
    }
    for(auto x:dis)
        cout<<x<<" ";
    cout<<endl;
    return;
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
    vector<vector<int>> edge(e,vector<int>(3,0));
;
    for(int i=0;i<e;i++)
    {
        cout<<"Enter from and to vertices of edge "<<i+1<<endl;
        cin>>edge[i][0]>>edge[i][1]>>edge[i][2];
    }

        bford(v,e,edge);
 return 0;
}
