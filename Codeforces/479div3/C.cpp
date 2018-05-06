#include <bits/stdc++.h>

using namespace std;

int n, k, a[200100];

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    if (k == 0 && a[0] == 1) {
        cout << -1 << '\n';
    } else if (k == 0) {
        cout << a[0] - 1 << '\n';
    } else {
        k--;
        if (k + 1 != n && a[k] == a[k + 1]) {
            cout << -1 << '\n';
        } else {
            cout << a[k] << '\n';
        }
    }

    return 0;
}