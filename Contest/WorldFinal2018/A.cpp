#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)a.size())
#define mp make_pair

const int maxn = 1e6 + 5;

vector<pair<int, int> > adj[maxn];
int tin[maxn], tou[maxn], vs[maxn];
int n, m;
double p[maxn], d[maxn];

priority_queue<pair<int, pair<int, int> > > st;

double dij() {
  rep(i, 0, n) d[i] = 0;
  d[0] = 1.0;
  st.push(mp(d[0], mp(0, 0)));
  while (sz(st)) {
    auto cur = st.top();
    st.pop();
    int u = cur.se.fi;
    if (u == 1) return d[u];
    int timeArrive = cur.se.se;
    if (vs[u]) continue;
    vs[u] = 1;
    cout << u << endl;
    for (auto now : adj[u]) {
      int v = now.fi;
      int id = now.se;
      if (v != 1) {
        if (timeArrive >= tin[id]) continue;
      } else {
        if (timeArrive )
      }
      double pro = cur.fi * p[id];
      if (d[v] < pro) {
        d[v] = pro;
        st.push(mp(d[v], mp(v, tou[id])));
      }
    }
  }
  return -1;
}

int main() {
  cin >> n >> m;

  rep(i, 0, m) {
    int a, b;
    scanf("%d%d%d%d%lf", &a, &b, &tin[i], &tou[i], &p[i]);
    adj[a].pb(mp(b, i));
    adj[b].pb(mp(a, i));
  }

  printf("%.12lf", dij());

  return 0;
}