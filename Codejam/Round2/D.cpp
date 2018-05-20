#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define repd(i, a, b) for (int i = (a) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) ((int)a.size())

int T, n, m, has[101][101];
string s[1010], ns[1010], olds[1010];
int tc;

int main() {
  cin >> T;

  while (T--) {
    cin >> n >> m;
    int oldn = n, oldm = m;
    rep(i, 0, n) {
      cin >> s[i];
      olds[i] = s[i];
    }
    rep(i, 0, 2) {
      rep(j, 0, 2 * n) ns[j] = "";
      rep(j, 0, n) {
        rep(k, 0, m) {
          ns[2 * j].pb(s[j][k]);
          ns[2 * j].pb(s[j][k]);
          ns[2 * j + 1].pb(s[j][k]);
          ns[2 * j + 1].pb(s[j][k]);
        }
      }
      rep(j, 0, 2 * n) s[j] = ns[j];
      n *= 2;
      m *= 2;
    }
//    rep(i, 0, n) {
//      cout << s[i] << endl;
//    }
    int tot = oldn * oldm;
    int ans = 0;
    rep(mask, 0, (1 << tot)) {
      int cnt = 0;
      rep(i, 0, oldn) {
        rep(j, 0, oldm) {
          int now = i * oldm + j;
          if ((mask & (1 << now)) != 0) {
            cnt++;
            has[i][j] = 1;
          } else has[i][j] = 0;
        }
      }

      int check = 0;
      rep(i, 0, n - oldn) {
        if (check) break;
        rep(j, 0, m - oldm) {
          int ok = 1;
          rep(i1, i, i + oldn) {
            rep(j1, j, j + oldm) {
              if (has[i1 - i][j1 - j] == 0) continue;
              if (olds[i1 - i][j1 - j] != s[i1][j1]) {
                if (cnt == 8 && i == 0 && j == 6) {
//                  cout << i1 << ' ' << j1 << olds[i1 - i][j1 - j] << endl;
                }
                ok = 0;
                break;
              }
            }
            if (!ok) break;
          }
          if (ok) check = 1;
        }
      }

      if (check && cnt == 5) {
        cout << 'F' << endl;
        rep(i, 0, oldn) {
          rep(j, 0, oldm) {
            cout << has[i][j] << ' ';
          }
          cout << endl;
        }
      }
      if (check) ans = max(ans, cnt);
    }

    printf("Case #%d: %d\n", ++tc, ans);
  }

  return 0;
}


