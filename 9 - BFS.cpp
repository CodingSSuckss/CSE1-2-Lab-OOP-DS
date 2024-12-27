#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e5+5;
bool visited[N];

void bfs(int u, vector<int> adjlist[])
{
    queue<int> q;
    q.push(u);

    while(!q.empty())
    {
        int p = q.front();

        if(visited[p]){
            q.pop();
            continue;
        }

        visited[p] = true;

        cout<<p<<" ";
        q.pop();

        for(auto c: adjlist[p])
        {
            if(visited[c]) continue;
            q.push(c);
        }
     }
}

int main()
{
    cout<<"Number of Nodes: ";
    int v;  cin >> v;

    cout<<"Number of Edges: ";
    int e;  cin >> e;

    cout<<"Enter Edges: "<<endl;
    int a,b;
    vector<int> adjlist[v+1];
    for(int i=0; i<e; i++)
    {
        cin >> a >> b;
        adjlist[a].pb(b);
    }

    bfs(1,adjlist);

//    for(int i=1; i<=v; i++){
//        cout<<"Node "<<i<<"Connected with: ";
//        for(auto x: adjlist[i]){
//            cout<<x<<" ";
//        }
//        cout<<endl;
//    }

    return 0;
}

