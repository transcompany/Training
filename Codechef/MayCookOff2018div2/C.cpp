#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 5;

int T, n;
long long k;
int ans[maxn];

int main() {
  cin >> T;

  while (T--) {
    cin >> n >> k;
    if (n == 1) {
      cout << k << '\n';
      continue;
    }
    if (k == 1) {
      for (int i = 0; i < n; i++) cout << 1 << ' ';
      puts("");
      continue;
    }
    long long cur = 1;
    while (cur - 1 < k) cur *= 2;
    cur--;
    long long rem = cur ^ k;
    if (rem == 0) {
      if (n % 2 == 0) {
        if (k % 2) k ^= 1;
        ans[0] = k;
        for (int i = 1; i < n; i++) ans[i] = 1;
      } else {
        ans[0] = k;
        for (int i = 1; i < n; i++) ans[i] = 1;
      }
    } else {
      if (n % 2 == 1) {
        if (rem != 1) rem ^= 1;
        else if (k % 2) k ^= 1;
      }
      ans[0] = k;
      ans[1] = rem;
      for (int i = 2; i < n; i++) ans[i] = 1;
    }

//    cout << cur << endl;
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    puts("");
  }

  return 0;
}
