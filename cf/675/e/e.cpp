#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
int n;
vi a, dp;
vvii table;

int logfloor(int x) {
  return x ? __builtin_clzll(1) - __builtin_clzll(x) : -1;
}

int32_t main() {
  int n;
  cin >> n;
  a.assign(n, 0);
  dp.assign(n, 0);
  table.assign(25, vii(n, {0, 0}));
  for (int i = 0; i < n-1; ++i) {
    cin >> a[i];
    --a[i];
    dp[i] = n-i-1;
    table[0][i] = {a[i], i};
  }

  for (int k = 1; k < 25; ++k) {
    for (int i = 0; i + (1<<k) <= n; ++i) {
      if (table[k-1][i].first > table[k-1][i + (1<<(k-1))].first) {
	table[k][i] = table[k-1][i];
      } else {
	table[k][i] = table[k-1][i + (1<<(k-1))];
      }
    }
  }

  dp[n-1] = 0;
  for (int i = n-2; i >= 0; --i) {
    int k = logfloor(a[i] - i + 1);
    int j = 0;
    if (table[k][i].first > table[k][a[i] - (1 << k)+1].first) {
      j = table[k][i].second;
    } else {
      j = table[k][a[i] - (1 << k) + 1].second;
    }
    dp[i] = dp[j] - (a[i] - j) + n-1 - i;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += dp[i];
  }
  cout << ans << endl;
}
