#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define sz(a) ((int)a.size())

typedef long long ll;

int n, ans[5010], pos[5010], vs[5010], G, has[5010];
vector<int> adj[5010];
ll a[5010];

int check(ll x) {
  if (x < 0) return 0;
  ll l = round(sqrt(x));
  if (l * l == x) return 1;
  return 0;
}

void dfs(int u) {
  pos[u] = G;
  vs[u] = 1;
  for (int i = 0; i < sz(adj[u]); i++) {
    int v = adj[u][i];
    if (vs[v]) continue;
    dfs(v);
  }
}

int main() {
  cin >> n;

  rep(i, 0, n) cin >> a[i];

  rep(i, 0, n) {
    rep(j, i, n) {
      if (i == j) continue;
      if (check(a[i] * a[j])) {
        adj[i].pb(j);
        adj[j].pb(i);
      }
    }
  }

  rep(i, 0, n) {
    if (!vs[i]) {
      G++;
      dfs(i);
    }
  }

  rep(i, 0, n) {
    int cnt = 0;
    rep(j, 1, n + 1) has[j] = 0;
    rep(j, i, n) {
      has[pos[j]]++;
      if (has[pos[j]] == 1) cnt++;
      ans[cnt]++;
    }
  }

  rep(i, 1, n + 1) cout << ans[i] << ' ';

  return 0;
}