#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define sz(a) ((int)a.size())

const int maxn = 1e5 + 5;

int n, k, a[maxn], pos[maxn];

int main() {

  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];

  rep(i, 0, 256) pos[i] = -1;

  rep(i, 0, n) {
    int l = max(0, a[i] - k + 1);
    // cout << l << endl;
    if (~pos[a[i]]) continue;
    // cout << i << endl;
    if (pos[l] != -1) {
      int pre = pos[l];
      // cout << a[i - pre + 1 << endl;
      if (a[i] - pre + 1 <= k) {
        rep(j, pre, a[i] + 1) {
          pos[j] = pre;
        }
      } else {
        while (true) {
          int cur = pos[l];
          if (!~cur) break;
          if (a[i] - cur + 1 <= k) break;
          l++;
        }
        rep(j, l, a[i] + 1) {
          pos[j] = l;
        }
      }
    } else {
      // cout << i << endl;
      rep(j, l, a[i] + 1) {
        pos[j] = l;
      }
    }
  }

  rep(i, 0, n) printf("%d ", pos[a[i]]);

  return 0;
}