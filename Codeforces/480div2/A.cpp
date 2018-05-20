#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define sz(a) ((int)a.size())

string s;

int main() {
  cin >> s;

  int cnt1 = 0, cnt2 = 0;
  rep(i, 0, sz(s)) {
    if (s[i] == 'o') cnt1++;
    else cnt2++;
  }

  if (cnt1 == 0 || cnt2 == 0) {
    cout << "YES";
    return 0;
  }

  if (cnt2 % cnt1 == 0) {
    cout << "YES";
    return 0;
  }

  cout << "NO";

  return 0;
}