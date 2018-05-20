#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define sz(a) ((int)a.size())

int n, k;
char a[200][200];

int main() {

  cin >> n >> k;

  rep(i, 0, 4) {
    rep(j, 0, n) a[i][j] = '.';
  }

  if (k % 2 == 0) {
    cout << "YES" << '\n';
    rep(j, 1, n - 1) {
      rep(i, 1, 3) {
        if (!k) break;
        a[i][j] = '#';
        k--;
      }
      if (!k) break;
    }
    rep(i, 0, 4) {
      rep(j, 0, n) cout << a[i][j];
      cout << '\n';
    }
    return 0;
  }

  if (k >= n - 2) {
    cout << "YES" << '\n';
    rep(i, 1, min(k + 1, n - 1)) {
      a[1][i] = '#';
    }
    int pos = min(k, n - 2);
    k -= min(k, n - 2);

    for (int i = pos; i >= pos - k + 1; i--) {
      a[2][i] = '#';
    }
    rep(i, 0, 4) {
      rep(j, 0, n) cout << a[i][j];
      cout << '\n';
    }
    return 0;
  }

  if (k <= 3) {
    cout << "NO";
    return 0;
  }

  cout << "YES" << '\n';
  rep(i, 1, k - 1) {
    a[1][i] = '#';
  }
  a[2][k - 2] = '#';
  a[2][1] = '#';
  rep(i, 0, 4) {
    rep(j, 0, n) cout << a[i][j];
    cout << '\n';
  }

  return 0;
}