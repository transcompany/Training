#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define sz(a) ((int)a.size())

int n;
string s;

int main() {
  cin >> n;
  cin >> s;

  rep(i, 0, sz(s)) {
    int d1 = 1, d2 = 1;
    if (s[i] == '1') {
      if (i && s[i - 1] == '1') {
        cout << "No";
        return 0;
      }
      if (i != sz(s) - 1 && s[i + 1] == '1') {
        cout << "No";
        return 0;
      }
      continue;
    }
    if (i) {
      if (s[i - 1] == '1') {
        d1 = 0;
      }
    }
    if (i != sz(s) - 1) {
      if (s[i + 1] == '1') {
        d2 = 0;
      }
    }
    if (d1 && d2) {
      cout << "No";
      return 0;
    }
  }

  cout << "Yes";

  return 0;
}
