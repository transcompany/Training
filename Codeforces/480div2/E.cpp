#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define sz(a) ((int)a.size())

const int maxn = 1e6 + 5;

int n, k;
int deg[maxn], zz[maxn];
set<int> st;
vector<int> adj[maxn], d[maxn];
set<int> s;

int main() {
  cin >> n >> k;

  rep(i, 0, n - 1) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  rep(i, 0, n) {
    deg[i] = sz(adj[i]);
    if (deg[i] == 1) {
      st.push(-i);
    }
  }

  set<int> ans;
  int check = 0;
  while (!check || sz(ans) < k) {
    check = 1;
    int cur = *st.begin();
    st.erase(cur);
    rep(i, 0, sz(d[cur])) {
      s.erase(d[cur][i]);
    }
    rep(i, 0, sz(adj[cur])) {
      int v = adj[cur][i];
      deg[v]--;
      if (deg[v] == 1) {
        st.insert(v);
        d[v].pb(cur);
        s.insert(cur);
        zz[cur] = v;
      }
    }
    if (sz(ans) < k) ans.insert(cur);
    else {
      set<int>::iterator it = ans.upper_bound(cur);
      if (it == ans.end()) continue;
      int now = *it;
      ans.erase(now);
      ans.insert(cur);
      rep(i, 0, sz(d[now])) {
        s.insert(d[now][i]);
      }
      st.insert(now);
      deg[zz[now]]++;
      st.erase(zz[now]);
      check = 0;
    }
  }

  for (set<int>::iterator it=ans.begin(); it != ans.end; it++) printf("%d ", (*it) + 1);

  return 0;
}