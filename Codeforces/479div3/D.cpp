#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e2 + 5;
int n, pre[maxn], nxt[maxn], vs[maxn];
long long a[maxn];

void go(int u) {
    if (!~u || vs[u]) return;
    vs[u] = 1;
    cout << a[u] << ' ';
    go(nxt[u]);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        nxt[i] = -1;
        pre[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] * 3 == a[j]) {
                // if (i == 0 && j == 4) cout << "Here " << endl;
                if (nxt[j] == -1 && pre[i] == -1) {
                    nxt[j] = i;
                    pre[i] = j;
                    // cout << '0' << i << ' ' << j << endl;
                }
            } else if (a[i] == a[j] * 2) {
                if (nxt[j] == -1 && pre[i] == -1) {
                    nxt[j] = i;
                    pre[i] = j;
                    // cout << '1' << i << ' ' << j << endl;
                }
            } if (a[j] * 3 == a[i]) {
                if (nxt[i] == -1 && pre[j] == -1) {
                    nxt[i] = j;
                    pre[j] = i;
                    // cout << '2' << i << ' ' << j << endl;
                }
            } else if (a[j] == a[i] * 2) {
                if (nxt[i] == -1 && pre[j] == -1) {
                    nxt[i] = j;
                    pre[j] = i;
                    // cout << '3' << i << ' ' << j << endl;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (pre[i] == -1) {
            go(i);
            puts("");
            return 0;
        }
    }

    go(0);
    puts("");
    return 0;
}