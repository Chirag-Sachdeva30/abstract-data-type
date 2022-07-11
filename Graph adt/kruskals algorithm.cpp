#include<bits/stdc++.h>
using namespace std;

void kruskals(int v,vector<vector<int>> &edge)
{
    vector<int> vis(v,0);
    int total=0,mn,curr,j;
    while(1)
    {
        mn=INT_MAX;
        j=0;
        for(auto x:edge)
        {
            if(vis[x[0]] && vis[x[1]])
                {
                    j++;
                    continue;
                }

            if(x[2]<mn)
            {
                mn=x[2];
                curr=j;
            }
            j++;
        }
        if(mn==INT_MAX)
            break;

        vis[edge[curr][0]]=1;
        vis[edge[curr][1]]=1;
        total+=mn;
    }
    cout<<total;
}
int main()
{
    cout<<"Enter the number of vertices(0 indexed)\n";
    int v;
    cin>>v;

    cout<<"Enter the number of edges\n";
    int e;
    cin>>e;
    vector<vector<int>> edge(e,vector<int>(3,0));
    int a,b;
    for(int i=0;i<e;i++)
    {
        cout<<"Enter from and to vertices of edge "<<i+1<<endl;
        cin>>edge[i][0]>>edge[i][1]>>edge[i][2];
    }

    //till here we have recieved all the input from the user;
    //now we will run bfs on the input;

    kruskals(v,edge);

    return 0;
}
