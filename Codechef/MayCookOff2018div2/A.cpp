#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define repd(i, a, b) for (int i = (a) - 1; i >= b; i--)
const int MOD = 1e9 + 7;
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}

template<class T> struct RangeCal2D {
    int n, m;
    vector<vector<T> > fen;
    
    void newTree(int _n, int _m) {
      n = _n, m = _m;
      fen.resize(n + 2, vector<T>(m + 2));
    }

    void resetTree() {
      for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
          fen[i][j] = 0;
        }
      }
    }

    void upd(int x, int y, T val) {
      addmod(fen[x + 1][y + 1], val);
    }

    void cal() {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (i) addmod(fen[i][j], fen[i - 1][j]);
          if (j) addmod(fen[i][j], fen[i][j - 1]);
          if (i && j) submod(fen[i][j], fen[i - 1][j - 1]);
        }
      }
    }

    T query(int x1, int y1, int x2, int y2) {
      T res = fen[x2 + 1][y2 + 1];
      submod(res, fen[x2 + 1][y1]);
      submod(res, fen[x1][y2 + 1]);
      addmod(res, fen[x1][y1]);
      return res;
    }
};

const int maxn = 305;
int T;
int n, m;
string s[maxn];
int pospre[maxn][maxn], posnxt[maxn][maxn];

int main() {
  cin >> T;

  while (T--) {
    cin >> n >> m;
    rep(i, 0, n) {
      cin >> s[i];
    }

    rep(j, 0, m) {
      int pre = -1;
      rep(i, 0, n) {
        if (s[i][j] != '#') {
          int pre = -1;
          repd(k, i + 1, 0) {
            if (s[k][j] == '#') {
              pre = k;
              break;
            }
          }
          int nxt = n;
          rep(k, i, n) {
            if (s[k][j] == '#') {
              nxt = k;
              break;
            }
          }
          pospre[i][j] = pre;
          posnxt[i][j] = nxt;
        }
      }
    }
    
    RangeCal2D<int> rf2d[2];
    rep(i, 0, 2) {
      rf2d[i].newTree(n, n);
      rf2d[i].resetTree();
    }
    rf2d[0].upd(0, n - 1, 1);
    rf2d[0].cal();
    int lv = 0;
    rep(i, 0, m) {
      rf2d[lv ^ 1].resetTree();
      rep(j, 0, n) {
        if (s[j][i] == '#') continue;
        rep(k, j + 1, n) {
          if (s[k][i] == '#') continue;
          int prej = pospre[j][i];
          int nxtj = posnxt[j][i];
          nxtj = min(nxtj, k);
          int prek = pospre[k][i];
          prek = max(prek, j);
          int nxtk = posnxt[k][i];
          int res = rf2d[lv].query(prej + 1, prek + 1, nxtj - 1, nxtk - 1);
//          if (i == 0) cout << j << ' ' << k << ' ' << prej + 1 << ' ' << nxtj - 1 << ' ' << prek + 1 << ' ' << nxtk - 1 << ' ' << res << endl;
          rf2d[lv ^ 1].upd(j, k, res);
        }
      }
      rf2d[lv ^ 1].cal();
      lv ^= 1;
    }

    int ans = rf2d[lv].query(0, n - 1, 0, n - 1);
    cout << ans << '\n';
  }

  return 0;
}
