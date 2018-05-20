#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)a.size())

typedef long long ll;

long long n;

int main() {

  cin >> n;

  if (n % 2 == 0) {
    cout << n + 1ll;
    return 0;
  } else {
    cout << (n + 1ll) / 2ll;
  }

  return 0;
}