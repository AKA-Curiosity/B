#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(int start, const vector<vector<int>>& graph, int n) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : graph[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main() {
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    vector<vector<int>> train(n + 1);
    vector<vector<bool>> rail(n + 1, vector<bool>(n + 1, false));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        train[u].push_back(v);
        train[v].push_back(u);
        rail[u][v] = rail[v][u] = true;
    }

    vector<vector<int>> bus(n + 1);
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            if (u != v && !rail[u][v]) {
                bus[u].push_back(v);
            }
        }
    }

    vector<int> dist_train = bfs(1, train, n);
    vector<int> dist_bus = bfs(1, bus, n);

    if (dist_train[n] == -1 || dist_bus[n] == -1) {
        cout << -1 << "\n";
    } else {
        cout << max(dist_train[n], dist_bus[n]) << "\n";
    }

    return 0;
}
