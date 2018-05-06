#include <bits/stdc++.h>

using namespace std;

#define sz(a) ((int)a.size())
#define pb push_back

const int maxn = 2e5 + 5;

vector<int> adj[maxn];
int n, m, found;
int vs[maxn];

void dfs(int u) {
    // cout << u << endl;
    if (sz(adj[u]) != 2) found = 0;
    if (vs[u]) return;
    vs[u] = 1;
    for (auto v : adj[u]) {
        dfs(v);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (vs[i]) continue;
        found = 1;
        dfs(i);
        ans += found;
    }

    cout << ans << '\n';

    return 0;
}