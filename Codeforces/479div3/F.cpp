#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int maxn = 2e5 + 5;

int n, a[maxn];
unordered_map<int, int> dp;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    dp[a[0]] = 1;

    int ans = 0, res = -1;
    for (int i = 0; i < n; i++) {
        dp[a[i]] = max(dp[a[i]], dp[a[i] - 1] + 1);
        if (dp[a[i]] > ans) {
            ans = dp[a[i]];
            res = i;
        }
    }

    vector<int> vans;
    vans.pb(res);
    for (int i = res - 1; i >= 0; i--) {
        if (a[i] == a[res] - 1) {
            vans.pb(i);
            res = i;
        }
    }

    reverse(vans.begin(), vans.end());
    cout << vans.size() << endl;
    for (auto v : vans) cout << v + 1 << ' ';
    cout << '\n';

    return 0;
}