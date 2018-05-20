#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)a.size())

const int maxn = 4e5 + 5;

int n;
int w[maxn], ans[maxn];
priority_queue<pair<int, int> > emp, ful;
string s;

int main() {
  cin >> n;

  rep(i, 0, n) {
    cin >> w[i];
    emp.push(mp(-w[i], i));
  }

  cin >> s;

  rep(i, 0, sz(s)) {
    if (s[i] == '0') {
      auto cur = emp.top();
      emp.pop();
      ans[i] = cur.se;
      ful.push(mp(-cur.fi, cur.se));
    } else {
      auto cur = ful.top();
      ful.pop();
      ans[i] = cur.se;
    }
  }

  rep(i, 0, n * 2) {
    printf("%d ", ans[i] + 1);
  }

  return 0;
}
