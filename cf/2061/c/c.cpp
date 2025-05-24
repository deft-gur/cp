#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int mod = 998244353;
int n;
vi a;
vvi dp;

int main() {
  int t; cin >> t;
  while (t--) {
    cin >> n;
    a.assign(n+1, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    dp.assign(n+1, vi(2, 0));
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i = 1; i <= n; ++i) {
      dp[i][1] = dp[i-1][0];
      dp[i][1] %= mod;
      if ((i == 2 && a[2]==1) || a[i] == a[i-2] + 1) {
	dp[i][0] += dp[i-1][1];
	dp[i][0] %= mod;
      }
      if ((i == 1 && a[1] == 0) || a[i] == a[i-1]) {
	dp[i][0] += dp[i-1][0];
	dp[i][0] %= mod;
      }
    }
    cout << (dp[n][0] + dp[n][1]) % mod << endl;
  }

}
