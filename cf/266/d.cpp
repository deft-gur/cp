#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define MOD (ll)(1e9 + 7)
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef vector<int> vi;
int n, h;
vll dp;
vi a;

ll modMul(ll x, ll y) { return (x * y) % MOD; }

ll modAdd(ll x, ll y) { return (((x + y) % MOD) + MOD) % MOD; }

int32_t main() {
  cin >> n >> h;
  a.assign(n+1, 0);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  
  dp.assign(n+1, vl(n+1, 0));
  dp[1][0] = (((a[1] == h) || (a[1] == h-1)) ? 1 : 0);
  dp[1][1] = ((a[1] == h-1) ? 1 : 0);
  for (int i = 2; i <= n; ++i) {
    for (int j = max(0, h - a[i] - 1); j <= min(h-a[i], i); ++j) {
      if (a[i] + j == h) {
	// Close one of j and not open 
	if (j > 0) dp[i][j-1] = modAdd(dp[i][j-1], modMul(dp[i-1][j], j));
	// Do nothing
	dp[i][j] = modAdd(dp[i][j], dp[i-1][j]);
      } else if (a[i] + j == h-1) {
	// Close one of j and open
	dp[i][j] = modAdd(dp[i][j], modMul(dp[i-1][j], j));
	// Open
	dp[i][j+1] = modAdd(dp[i][j+1], dp[i-1][j]);
	// Open and close on ith element
	dp[i][j] = modAdd(dp[i][j], dp[i-1][j]);
      }
    }
  }

  cout << dp[n][0] << '\n';
  return 0;
}
