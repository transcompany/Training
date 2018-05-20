#include <bits/stdc++.h>

using namespace std;

int T, x1, x2, x3, v1, v2;

int main() {
  cin >> T;

  while (T--) {
    cin >> x1 >> x2 >> x3;
    cin >> v1 >> v2;
    int d1 = abs(x3 - x1);
    int d2 = abs(x3 - x2);
    long long a = (long long) d1 * v2;
    long long b = (long long) d2 * v1;
    if (a < b) puts("Chef");
    else if (a > b) puts("Kefa");
    else puts("Draw");
  }

  return 0;
}
