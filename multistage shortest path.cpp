#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<pair<int, int>> adj[N];

int dist[N];
int path[N];

void shortestPathMultistage(int n) {
    for(int i = 1; i <= n; i++) dist[i] = INT_MAX;
    int source = 1;
    dist[source] = 0;

    for (int u = source; u <= n; u++) {
        for (auto x : adj[u]) {
            int v = x.first;
            int w = x.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                path[v] = u;
            }
        }
    }

    // COST
    cout << "Minimum cost from source to destination: " << dist[n] << endl;

    // PATH
    vector<int> shortestPath;
    for (int v = n; v != source; v = path[v]) {
        shortestPath.push_back(v);
    }
    shortestPath.push_back(source);

    reverse(shortestPath.begin(), shortestPath.end());

    for (int i : shortestPath) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    shortestPathMultistage(n);

    return 0;
}
