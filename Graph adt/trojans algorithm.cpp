 #include<bits/stdc++.h>
using namespace std;

void dfs(int i,int parent,vector<int> adj[], vector<int> &active,vector<int> &dis,vector<int> &low,int &curr,stack<int> &st,vector<vector<int>> &ans)
{
    dis[i]=++curr;
    active[i]=1;
    low[i]=dis[i];
    st.push(i);
    for(auto x:adj[i])
    {


            if(dis[x]==-1)
            {
                dfs(x,i,adj,active,dis,low,curr,st,ans);
                low[i]=min(low[x],low[i]);
            }
            else if(active[x])
              {
                  low[i]=min(low[x],low[i]);
              }

    }


         if(low[i]==dis[i])
        {
            vector<int> temp;
            int node;
            do{
                node=st.top();
                st.pop();
                temp.push_back(node);
            }while(node!=i);
            ans.push_back(temp);
             active[node]=0;
        }


        return;
}

void tarjans(int v, vector<int> adj[])
{
    vector<int>dis(v,-1);
    vector<int>low(v,INT_MAX);
    vector<int>active(v,0);
vector<vector<int>> ans;

    stack<int> st;
    int curr=0;
    for(int i=0;i<v;i++)
    {
        if(dis[i]==-1)
        {
            dfs(i,-1,adj,active,dis,low,curr,st,ans);
        }
    }
    cout<<endl<<"discovery times are"<<endl;
    for(auto x:dis)
        cout<<x<<" ";
    cout<<endl;
    cout<<"low times are"<<endl;
    for(auto x:low)
        cout<<x<<" ";

         for(auto &x:ans)
    sort(x.begin(),x.end());

    sort(ans.begin(),ans.end());

    cout<<endl;
        for(auto x:ans)
        {
            for(auto y:x)
            cout<<y<<" ";
                cout<<endl;
        }
}

int main()
{

    int v;
    cin>>v;
    vector<int> adj[v];

    int e;
    cin>>e;
    int a,b;
    for(int i=0;i<e;i++)
    {

        cin>>a>>b;
        adj[a].push_back(b);
    }

    //till here we have recieved all the input from the user;
    //now we will run bfs on the input;
    cout<<"strongly connected components are as follows:\n";
    tarjans(v, adj);
    return 0;
}
