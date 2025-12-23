#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);

    int n; cin >> n;

    vector<string> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    int a, b; cin >> a >> b;
    a--; b--;

    vector<int> dist(n, -1), parent(n, -1);
    queue<int> q;

    dist[a] = 0; q.push(a);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u = 0; u < n; u++) {
            if (g[v][u] == '1' && dist[u] == -1) {
                dist[u] = dist[v] + 1;
                parent[u] = v;
                q.push(u);
            }
        }
    }

    if (dist[b] == -1) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> path;
    for (int v = b; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    cout << dist[b] << '\n';
    for (int v : path)
        cout << v + 1 << ' ';
    cout << '\n';
    
    return 0;
}
