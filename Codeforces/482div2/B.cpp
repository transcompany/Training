#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)a.size())

int n;
string s[3];
int val[3], cnt[55];

int main() {

  cin >> n;

  for (int i = 0; i < 3; i++) {
    cin >> s[i];
    rep(j, 0, 55) cnt[j] = 0;
    rep(j, 0, sz(s[i])) {
      if (s[i][j] >= 'a' && s[i][j] <= 'z') {
        cnt[s[i][j] - 'a']++;
      } else {
        cnt[s[i][j] - 'A' + 26]++;
      }
    }
    int now = 0;
    rep(j, 0, 55) {
      now = max(now, cnt[j]);
    }
    int rem = sz(s[i]) - now;
    val[i] = now + min(rem, n);
    if (now == sz(s[i]) && n == 1) {
      val[i]--;
    }
  }

  // cout << val[0] << ' ' << val[1] << ' ' << val[2] << endl;
  if (val[0] > val[1] && val[0] > val[2]) cout << "Kuro";
  else if (val[1] > val[2] && val[1] > val[0]) cout << "Shiro";
  else if (val[2] > val[1] && val[2] > val[0]) cout << "Katie";
  else cout << "Draw";
  return 0;
}