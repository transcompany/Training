#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)a.size())

const int maxn = 3e5 + 5;
const int oo = 1e9 + 5;

vector<pair<int, int> > trie[maxn];
vector<int> val[maxn];
int cnt[maxn];
int vs[maxn];
int q;

void addTrie(int id, int v) {
  int now = 0;
  for (int i = 18; i >= 0; i--) {
    if ((v & (1 << i)) != 0) {
      int nxt = trie[id][now].se;
      if (nxt == 0) {
        trie[id][now].se = ++cnt[id];
        trie[id].pb(mp(0, 0));
        val[id].pb(oo);
      }
      now = trie[id][now].se;
      val[id][now] = min(val[id][now], v);
      v -= (1 << i);
    } else {
      int nxt = trie[id][now].fi;
      if (nxt == 0) {
        trie[id][now].fi = ++cnt[id];
        trie[id].pb(mp(0, 0));
        val[id].pb(oo);
      }
      now = trie[id][now].fi;
      val[id][now] = min(val[id][now], v);
    }
  }
}

int getTrie(int id, int v, int s) {
  int now = 0;
  int ans = 0;
  for (int i = 18; i >= 0; i--) {
    int res = -1;
    int zz = ((v & (1 << i)) != 0);
    int cur = trie[id][now].fi;
    int hihi = -1;
    // if (i == 1) cout << cur << endl;
    if (cur != 0) {
      if (val[id][cur] + v + ans <= s) {
        res = (zz ^ 0);
        hihi = 0;
      }
    }
    cur = trie[id][now].se;
    if (cur != 0) {
      if (val[id][cur] + v + ans <= s) {
        if (res < (zz ^ 1)) {
          hihi = 1;
        }
      }
    }
    if (hihi == -1) return -1;
    if (hihi == 1) {
      now = trie[id][now].se;
      ans += (1 << i);
    } else now = trie[id][now].fi;
  }
  assert(__gcd(ans, v) % id == 0);
  assert(ans + v <= s);
  return ans;
}

void them(int u) {
  for (int i = 1; i * i <= u; i++) {
    if (u % i == 0) {
      addTrie(i, u);
      if (u / i != i) addTrie(u / i, u);
    }
  }
}

int main() {
  rep(i, 0, maxn) {
    trie[i].pb(mp(0, 0));
    val[i].pb(0);
  }
  cin >> q;
  rep(i, 0, q) {
    int type, u, x, k, s;
    scanf("%d", &type);
    if (type == 1) {
      scanf("%d", &u);
      if (vs[u]) continue;
      vs[u] = 1;
      them(u);
    } 
    else {
      scanf("%d%d%d", &x, &k, &s);
      if (x % k != 0) puts("-1");
      else printf("%d\n", getTrie(k, x, s));
    }
  }

  return 0;
}