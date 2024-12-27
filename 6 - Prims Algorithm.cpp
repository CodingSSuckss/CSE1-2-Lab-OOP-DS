#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
bool visited[N];

class Edge
{
public:
    int a,b,w;

    Edge(int a,int b, int w)
    {
        this -> a = a;
        this -> b = b;
        this -> w = w;
    }
};

class cmp
{
public:
    bool operator()(Edge a,Edge b)
    {
        return a.w > b.w;
    }
};

void prims(int s,vector<pair<int,int>> adj[]){

    priority_queue<Edge,vector<Edge>,cmp> pq;
    pq.push(Edge(s,s,0));
    vector<Edge> edgelist;

    while(!pq.empty())
    {
       Edge parent = pq.top();
       int a = parent.a;
       int b = parent.b;
       int w = parent.w;

       pq.pop();
       if(visited[b]) continue;
       visited[b] = true;
       edgelist.push_back(parent);

       for(auto c: adj[b])
       {
         int x = c.first;  //c
         int y = c.second; //w

         if(visited[x]) continue;
         pq.push(Edge(b,x,y));
       }
    }

    //printing EdgeLists
    for(auto x: edgelist)
    {
        cout<<x.a<<" "<<x.b<<" "<<x.w<<endl;
    }
}

int main()
{
    cout<<"Enter  number of vertex and edges: ";
    int n,e,u,v,w; cin >> n >> e;

    cout<<"Enter Edges With Weights: "<<endl;
    vector<pair<int,int>> adj[n];

    for(int i=0; i<e; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    prims(1,adj);

    return 0;
}
