#include <bits/stdc++.h>

#define long long int
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
int n, m, l;
vvi dp, g;

void bfs() {
  queue<ii> q;
  q.push({0, 0});
  dp[0][0] = 0;
  while(!q.empty()) {
    auto [v, p] = q.front(); q.pop();
    for (auto u : g[v]) {
      if (dp[u][!p] > dp[v][p] + 1) {
	dp[u][!p] = dp[v][p] + 1;
	q.push({u, !p});
      }
    }
  }
}

void solve() {
  cin >> n >> m >> l;
  int sum = 0;
  int minodd = 2e9+1;
  dp.assign(n, vi(2, 2e9+1));
  g.assign(n, vi());
  for (int i = 0; i < l; ++i) {
    int s;
    cin >> s;
    sum += s;
    if (s % 2 == 1) minodd = min(minodd, s);
  }
  if (minodd == 2e9+1) minodd = 0;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  bfs();
  vi ans;
  ans.assign(n, 0);
  for (int i = 0; i < n; ++i) {
    if ((sum >= dp[i][sum % 2]) || (sum - minodd >= dp[i][abs((sum - minodd) % 2)])) {
      ans[i] = 1;
    }
  }
  ans[0] = 1;
  for (int i = 0; i < n; ++i) cout << ans[i];
  cout << endl;
}

int32_t main() {
  int t;
  cin >> t;
  while(t--) solve();
}
