#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define repd(i, a, b) for (int i = (a) - 1; i >= b; i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) ((int)a.size())

string s[300];
int C, a[101];

int main() {
  int T, tc = 0;

  cin >> T;

  while (T--) {
    cin >> C;
    rep(i, 0, C) cin >> a[i];

    int pos = 0;
    int row = 0;
    if (a[0] == 0 || a[C - 1] == 0) {
      printf("Case #%d: IMPOSSIBLE\n", ++tc); 
      continue;
    }
    rep(i, 0, C) {
      int cnt1 = 0, cnt2 = 0;
      rep(j, 0, a[i]) {
        if (pos != i) {
          if (pos < i) {
            cnt1++;
          } else {
            cnt2++;
          }
        }
        pos++;
      }
      row = max(row, max(cnt1 + 1, cnt2 + 1));
    }

    rep(i, 0, row) {
      rep(j, 0, C) {
        s[i][j] = '.';
      }
    }
    pos = 0;
    rep(i, 0, C) {
      rep(j, 0, a[i]) {
        if (pos != i) {
          if (pos < i) {
            int now = 0;
            rep(k, pos, i) {
              s[now][k] = '\\';
              now++;
            }
          } else {
            int now = 0;
            repd(k, pos + 1, i + 1) {
              s[now][k] = '/';
              now++;
            }
          }
        }
        pos++;
      }
    }

    printf("Case #%d: %d\n", ++tc, row);
    rep(i, 0, row) {
      rep(j, 0, C) {
        cout << s[i][j];
      }
      cout << '\n';
    }
  }

  return 0;
}
