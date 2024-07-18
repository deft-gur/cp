#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MX 300005

int n;
int a[MX];
vector<int> AL[MX];
int dp[MX][32];
int visited[MX];

// NEED fix: dp state is:
// NOTE the round is at most log(n).
// For b, we need at least 2^b nodes. At round 1 there is 2^(b-1) node elimnated which connects to the other 2^(b-1) nodes. And this process continues.
// So let dp[i][b] denote the min cost subtree rooted at node i is eliminated at round b.
// dp[i][0] = a_i
// dp[i][b] = a_i * b + sum_(j in child of i) min_(1 <= c <= log(n), c != b) dp[j][c]
// ANS: min_(b) dp[0][b]
// Time complexity: n * log(n)

int dfs(int v, int p, int h) {
  int ret = 3e18;
  for (int b = 1; b < 32; ++b) {
    if (b == h) continue;
    int &res = dp[v][b];
    if (res) {
      ret = min(ret, res);
      continue;
    }
    
    res = a[v] * b;
    for (auto u : AL[v]) {
      if (u == p) continue;
      res += dfs(u, v, b);
    }
    ret = min(ret, res);
  }
  return ret;
}

void solve() {
  cin >> n;
  memset(a, 0, sizeof a);
  memset(visited, 0, sizeof visited);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    AL[i].clear();
    memset(dp[i], 0, sizeof dp[i]);
  }


  int u, v;
  for (int i = 0; i < n-1; ++i) {
    cin >> u >> v;
    --v, --u;
    AL[u].emplace_back(v);
    AL[v].emplace_back(u);
  }
  cout << dfs(0, -1, 0) << endl;
}


int32_t main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}
