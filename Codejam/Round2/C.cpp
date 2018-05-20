#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define repd(i, a, b) for (int i = (a) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) ((int)a.size())

template<class T, T oo> struct Dinic {
    static const int MAXV = 1e5 + 5;
    static const int MAXE = 1e6 + 5;
    int n, s, t, E;
    int adj[MAXE], nxt[MAXE], lst[MAXV], ptr[MAXV], lev[MAXV], que[MAXV];
    T flw[MAXE], cap[MAXE];
    void init(int n, int s, int t) {
        this->n = n, this->s = s, this->t = t, E = 0;
        fill_n(lst, n, -1);
    }
    void add(int u, int v, T c1, T c2) {
        adj[E] = v, flw[E] = 0, cap[E] = c1, nxt[E] = lst[u], lst[u] = E++;
        adj[E] = u, flw[E] = 0, cap[E] = c2, nxt[E] = lst[v], lst[v] = E++;
    }
    int bfs() {
        fill_n(lev, n, 0), lev[s] = 1;
        int qsize = 0;
        que[qsize++] = s;
        for (int i = 0; i < qsize; i++) {
            for (int u = que[i], e = lst[u]; ~e; e = nxt[e]) {
                int v = adj[e];
                if (flw[e] < cap[e] && !lev[v]) {
                    lev[v] = lev[u] + 1;
                    que[qsize++] = v;
                }
            }
        }
        return lev[t];
    }
    T dfs(int u, T bot) {
        if (u == t) return bot;
        for (int& e = ptr[u]; ~e; e = nxt[e]) {
            int v = adj[e];
            T delta = 0;
            if (lev[v] == lev[u] + 1 && flw[e] < cap[e] && (delta = dfs(v, min(bot, cap[e] - flw[e]))) > 0) {
                flw[e] += delta; flw[e ^ 1] -= delta;
                return delta;
            }
        }
        return 0;
    }
    T maxflow(int ss = -1, int tt = -1) {
        if (~ss) s = ss;
        if (~tt) t = tt;
        for (int e = 0; e < E; e++) {
            flw[e] = 0;
        }
        T total = 0;
        while (bfs()) {
            for (int i = 0; i < n; i++) ptr[i] = lst[i];
            for (T delta = dfs(s, oo); delta > 0; delta = dfs(s, oo)) total += delta;
        }
        return total;
    }
    vector<pair<pair<int, int>, T> > gomory_hu() {
        vector<pair<pair<int, int>, T> > tree;
        vector<int> p(n);
        for (int u = 1; u < n; u++) {
            tree.push_back(make_pair(make_pair(p[u], u), maxflow(u, p[u])));
            for (int v = u + 1; v < n; ++v) {
                if (lev[v] && p[v] == p[u]) {
                    p[v] = u;
                }
            }
        }
        return tree;
    }
};
Dinic<int, (int) 1e9> dinic;

int T, tc;
int n, a[101][101];

int main() {
  cin >> T;

  while (T--) {
    cin >> n;
    rep(i, 0, n) {
      rep(j, 0, n) {
        cin >> a[i][j];
      }
    }

    int ans = 0;
    rep(k, -n, n + 1) {
      vector<pair<int, int> > has;
      rep(i, 0, n) {
        rep(j, 0, n) {
          if (a[i][j] == k) {
            has.pb(mp(i, j));
          }
        }
      }
      if (sz(has) == 0) continue;
      int tot = n * 2 + sz(has);
//      cout << "H" << endl;
      dinic.init(tot + 2, tot, tot + 1); // here
//      cout << tot << ' ' << tot - 2<< ' ' << tot - 1 << endl;
      rep(i, 0, sz(has)) {
         auto v = has[i];
//         cout << v.fi << ' ' << 2 * n + i << ' ' << v.se + n << endl;
         dinic.add(v.fi, 2 * n + i, 1, 0);
         dinic.add(2 * n + i, v.se + n, 1, 0);
      }
      rep(i, 0, n) {
        dinic.add(tot, i, 1, 0);
        dinic.add(i + n, tot + 1, 1, 0);
      }
      int res = dinic.maxflow();
//      cout << res << endl;
      res = sz(has) - res;
      ans += res;
    }

    printf("Case #%d: %d\n", ++tc, ans);
  }

  return 0;
}


