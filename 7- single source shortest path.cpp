#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int N = 1e5+5;
vector<pair<int,int>> adj[N];
int dist[N];

void set_dist(int n)
{
    for(int i=1; i<=n; i++)
    {
        dist[i] = INT_MAX;
    }
}

void dijkstra(int s) {
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap priority queue
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto x : adj[u]) {
            int v = x.first;
            int w = x.second;

            //path relaxation
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, e;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> e;

    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < e; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    set_dist(n);

    int start;
    cout << "Enter the start vertex: ";
    cin >> start;

    dijkstra(start);

    cout << "Shortest distances from vertex " << start << ":" << endl;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INT_MAX) {
            cout << "Vertex " << i << ": INF" << endl;
        } else {
            cout << "Vertex " << i << ": " << dist[i] << endl;
        }
    }

    return 0;
}
