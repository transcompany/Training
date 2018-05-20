#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back

const int maxn = 1e5 + 5;

int n;
vector<int> adj[maxn];
int dp[maxn][2];


void dfs(int u, int p = -1) {
  int tot = 0;
  int cnt = 0;
  int state = 1;
  int canrem = 0;
  for (auto v : adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    if (~dp[v][0]) {
      tot += dp[v][0];
      canrem++;
    } else {
      state++;
      tot += dp[v][1];
    }
    cnt++;
  }

  if (cnt == 0) {
//    cout << u << endl;
    dp[u][1] = 0;
    dp[u][0] = -1;
    return;
  }

  if (state % 2) {
    dp[u][1] = canrem + tot;
    dp[u][0] = -1;
    if (canrem) {
      for (auto v : adj[u]) {
        if (v == p || !~dp[v][0] || !~dp[v][1]) continue;
        int rem = tot - dp[v][0];
        rem += dp[v][1];
        rem += canrem - 1;
        dp[u][0] = max(dp[u][0], rem);
      }
    }
  } else {
//    if (u == 3) cout << canrem << ' ' << tot << endl;
    dp[u][0] = canrem + tot;
    dp[u][1] = -1;
    if (canrem) {
      for (auto v : adj[u]) {
        if (v == p || !~dp[v][0] || !~dp[v][1]) continue;
        int rem = tot - dp[v][0];
        rem += dp[v][1];
        rem += canrem - 1;
        dp[u][1] = max(dp[u][1], rem);
      }
    }
  }
}

int main() {
  cin >> n;

  rep(i, 0, n - 1) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    adj[x].pb(y);
    adj[y].pb(x);
  }

  dfs(0);

//  cout << dp[9][0] << endl;
  cout << dp[0][0];

  return 0;
}
