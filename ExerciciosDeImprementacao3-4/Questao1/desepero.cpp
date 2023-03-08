#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct Edge {
    int u, v, w;
};

vector<Edge> edges;
int dist[1005];
int c[1005];

void BellmanFord(int n, int m, int s, int Q) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (Edge e : edges) {
            if (dist[e.u] < INF && dist[e.u] >= e.w && c[e.u] <= Q) {
                dist[e.v] = min(dist[e.v], dist[e.u] + e.w * (Q - c[e.u]));
            }
        }
    }

    for (Edge e : edges) {
        if (dist[e.u] < INF && dist[e.u] >= e.w && c[e.u] <= Q && dist[e.v] > dist[e.u] + e.w * (Q - c[e.u])) {
            cout << "sem solucao" << endl;
            return;
        }
    }

    if (dist[t] == INF) {
        cout << "sem solucao" << endl;
        return;
    }
    cout << dist[t] << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    int x;
    cin >> x;
    while (x--) {
        int Q, s, t;
        cin >> Q >> s >> t;
        BellmanFord(n, m, s, Q);
    }
    return 0;
}
