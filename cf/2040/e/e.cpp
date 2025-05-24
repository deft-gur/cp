#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

void solve() {
  int n, q;
  cin >> n >> q;
  vvi tree;
  tree.assign(n, vi());
  for (int i = 0; i < n-1; ++i) {
    int u, v; cin >> u >> v; --u; --v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  vi dep, dp, par;
  dp.assign(n, 0);
  dep.assign(n, 0);
  par.assign(n, 0);
  function <void(int, int)> dfs = [&](int v, int p) {
    par[v] = p;
    if (dep[v] == 1) dp[v] = 1;
    if (dep[v] > 1) dp[v] = 2 * (int)tree[p].size() + dp[par[p]];
    for (auto u : tree[v]) {
      if (u == p) continue;
      dep[u] = dep[v] + 1;
      dfs(u, v);
    }
  };

  dfs(0, 0);

  while(q--) {
    int v, p; cin >> v >> p; --v;
    vi cnt;
    int res = dp[v];
    while(v != 0 && par[v] != 0) {
      cnt.push_back((int)tree[par[v]].size());
      v = par[par[v]];
    }
    sort(cnt.rbegin(), cnt.rend());
    for (int i = 0; i < min(p, (int)cnt.size()); ++i) {
      res -= 2 * cnt[i];
      res += 2;
    }
    cout << res << '\n';
  }
  dfs(0, 0);
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
