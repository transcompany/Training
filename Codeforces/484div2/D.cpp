#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define pos(v) ((v) << 1)
#define neg(v) (pos(v) ^ 1)

const int maxn = 2e5 + 5;

struct SSC {
    static const int MAXV = 2e5 + 5;
    int n;
    vector<int> forward[MAXV], backward[MAXV];
    int has[MAXV];
    int del[MAXV];
    int vs[MAXV];
    int vv[MAXV];
    bool used[MAXV];
    int cnt, order[MAXV], comp[MAXV];
    int pre[MAXV];
    void init(int _n) {
        n = _n;
        for (int i = 0; i < n; i++) {
            forward[i].clear();
            backward[i].clear();
        }
    }
    void add(int u, int v) {
        forward[u].push_back(v);
        backward[v].push_back(u);
    }
    void dfs1(int u) {
        used[u] = true;
        for (int i = 0; i < forward[u].size(); i++) {
            int v = forward[u][i];
            if (!used[v]) dfs1(v);
        }
        order[cnt++] = u;
    }
    void dfs2(int u, int c) {
        comp[u] = c;
        has[c]++;
        for (int i = 0; i < backward[u].size(); i++) {
            int v = backward[u][i];
            if (comp[v] == -1) dfs2(v, c);
        }
    }
    int hasscc() {
        cnt = 0;
        memset(used, 0, sizeof(used));
        for (int u = 0; u < n; u++) if (!used[u]) dfs1(u);
        memset(comp, -1, sizeof(comp));
        int c = 0;
        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];
            if (comp[u] == -1) dfs2(u, c++);
        }
        return c;
    }

    int check;
    void go(int u, int p) {
        pre[u] = p;
        vs[u] = 1;
        for (auto v : forward[u]) {
          if (check) return;
          if (del[v]) continue;
          if (vs[v]) {
            check = 1;
            int zz = u;
            del[v] = 1;
            while (zz != v) {
              del[zz] = 1;
              zz = pre[zz];
            }
            return;
          } else go(v, u);
        }
    }

    void gof(int u) {
      vs[u] = 1;
      for (auto v : forward[u]) {
        if (check != -1) return;
        if (del[v]) continue;
        if (vs[v]) {
          if (del[v]) {
            check = v;
            return;
          }
        }
        else gof(v);
      }
    }

    int solve() {
        memset(has, 0, sizeof(has));
        int tot = hasscc();
        int now = 0;
        if (tot != 1) {
          int cnt1 = 0;
          rep(i, 0, tot) {
            if (has[i] == 1) cnt1++;
            else now = i;
          }
          if (cnt1 != tot - 1) return -1;
        }

        memset(vv, 0, sizeof(vv));
        rep(i, 0, n - 1) {
          if (comp[i] == now) {
            vv[i] = 1;
          }
        }
        check = 0;
        memset(del, 0, sizeof(del));
        memset(vs, 0, sizeof(vs));
        rep(i, 0, n - 1) {
          if (vv[i]) {
            go(i, i);
            break;
          }
        }
        memset(vs, 0, sizeof(vs));
        check = 0;
        for (int i = 0; i < n - 1; i++) {
          if (vv[i] && !vs[i]) {
            go(i, i);
          }
        }
        if (check) return -1;
        int gg;
        memset(vs, 0, sizeof(vs));
        for (int i = 0; i < n; i++) {
          if (del[i]) {
            gg = i;
            check = -1;
            gof(i);
            if (check != -1) return i + 1;
          }
        }
        return gg;
    }
} scc;

int n, m;

int main() {
  cin >> n >> m;

  scc.init(n);
  rep(i, 0, m) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--; y--;
    scc.add(x, y);
  }

  cout << scc.solve();
}
