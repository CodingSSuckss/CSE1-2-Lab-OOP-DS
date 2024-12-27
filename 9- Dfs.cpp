#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
bool visited[N];

void dfs(int u,vector<int> adj[])
{
   visited[u] = true;
   cout<<u<<" ";
   for(auto c: adj[u])
   {
       if(visited[c]) continue;
       dfs(c,adj);
   }
}

int main()
{
    int n,e,u,v; cin >> n >> e;
    cout<<"Enter Edges: "<<endl;

    vector<int> adj[n];

    for(int i=0; i<e; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    dfs(1,adj);

    return 0;
}
