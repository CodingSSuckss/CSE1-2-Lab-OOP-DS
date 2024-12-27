#include<bits/stdc++.h>
#define pb push_back

using namespace std;

const int N = 1e5+5;
int parent[N];

void setParent(int n)
{
    for(int i=1; i<=n; i++)
    {
        parent[i] = -1;
    }
}

int dsu_find(int n)
{
    while(parent[n] != -1)
    {
        n = parent[n];
    }
    return n;
}

void dsu_union(int a,int b)
{
   int leaderA = dsu_find(a);
   int leaderB = dsu_find(b);

   if(leaderA != leaderB)
   {
       parent[leaderA] = leaderB;
   }
}

class Edge
{
public:
    int a,b,w;

    Edge(int a,int b,int w)
    {
        this-> a = a;
        this-> b = b;
        this-> w = w;
    }
};

bool cmp(Edge a,Edge b)
{
    return a.w < b.w ;
}

int main()
{
    int n,e;  cin >> n >> e;

    setParent(n);

    vector<Edge>v;
    while(e--)
    {
        int a,b,w;  cin >> a >> b >> w;
        v.push_back(Edge(a,b,w));
    }

    sort(v.begin(),v.end(),cmp);

    vector<Edge>ans;

    for(auto x: v)
    {
        int a = x.a;
        int b = x.b;
        int w = x.w;

        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        if(leaderA == leaderB) continue;
        dsu_union(a,b);

        ans.pb(x);
    }

    cout<<endl<<endl;
    for(auto x: ans)
    {
        cout<<x.a<<" "<<x.b<<" "<<x.w<<endl;
    }

    return 0;
}
