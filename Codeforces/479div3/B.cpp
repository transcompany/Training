#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {
    cin >> n;
    cin >> s;

    int ans = 0;
    string res = "";
    map<string, int> has;
    for (int i = 0; i < n - 1; i++) {
        string tmp = "";
        tmp += s[i];
        tmp += s[i + 1];
        has[tmp]++;
        if (has[tmp] > ans) {
            ans = has[tmp];
            res = tmp;
        }
    }

    cout << res;
    return 0;
}