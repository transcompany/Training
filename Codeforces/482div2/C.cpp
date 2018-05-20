#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)a.size())

const int maxn = 3e5 + 5;

int n, A, B, T;
vector<int> adj[maxn];
int tin[maxn], tou[maxn], _sz[maxn];

void dfs(int u, int p = -1) {
  tin[u] = T++;
  _sz[u] = 1;
  for (auto v : adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    _sz[u] += _sz[v];
  }
  tou[u] = T++;
}

int main() {

  cin >> n >> A >> B;
  A--; B--;
  swap(A, B);
  rep(i, 0, n - 1) {
    int x, y;
    cin >> x >> y;
    x--; 
    y--;
    adj[x].pb(y);
    adj[y].pb(x);
  }

  dfs(B);

  for (auto v : adj[B]) {
    if (tin[v] <= tin[A] && tou[v] >= tou[A]) {
      int rem = n - _sz[v];
      long long ans = (long long) rem * _sz[A];
      cout << (long long) n * (n - 1) - ans;
    }
  }

  return 0;
}