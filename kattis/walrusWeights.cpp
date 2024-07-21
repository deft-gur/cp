#include <bits/stdc++.h>

using namespace std;

#define MX 1005

int n;
int a[MX];
int memo[MX][MX];

inline int dist(int x, int y) {
  return abs(x - y);
}

int dp(int v, int i) {
  int idx = (v > 1000) ? 1000 : v;
  int &res = memo[idx][i];
  if (i == n) {
    if (res != -1) res = min(res, v);
    else res = v;
  }
  if (res != -1) return res;
  res = v;
  if (idx == 1000) return dp(v, n);
  int x = dp(v, i+1);
  int y = dp(v + a[i+1], i+1);
  return res;
}

void solve() {
  cin >> n;
  memset(memo, -1, sizeof memo);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  dp(0, 0);
  int m = 1000;
  int v = 0;
  for (int i = 1; i <= 1000; ++i) {
    m = min(m, dist(memo[i][n], 1000));
    if (m == dist(memo[i][n], 1000)) v = max(v, memo[i][n]);
  }
  cout << v << endl;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
}
