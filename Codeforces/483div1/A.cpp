#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define repd(i, a, b) for (int i = (a) - 1; i >= b; i--)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(a) ((int)a.size())

int n, cnt;
vector<int> a[5000];

int main() {
  a[0].pb(1);
  rep(i, 1, 5000) a[0].pb(0);
  rep(i, 1, 5000) {
    a[i].pb(1);
    cnt++;
    rep(j, 1, 5000) {
      if (j > i) a[i].pb(0);
      else a[i].pb(a[i - 1][j - 1] ^ a[i - 1][j]);
      if (a[i].back()) cnt++;
    }
  }

  // rep(i, 0, 20) {
  //   rep(j, 0, 20) cout << a[i][j] << ' ';
  //   cout << endl;
  // }
  cout << cnt;

  // cin >> n;

  // rep(i, 0, n) cin >> b[i];

  // cin >> q;
  
  // rep(i, 0, q) {
  //   int l, r;
  //   scanf("%d%d", &l, &r);
  //   l--; r--;
  //   has[l].pb(mp(i, 0));
  //   has[r].pb(mp(i, 1));
  // }

  // rep(i, 0, n) {
    
  // }

  return 0;
}