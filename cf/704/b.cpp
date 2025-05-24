#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MOD (ll)(1e9+7)
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef vector<vll> vlll;

vl x, a, b, c, d;
vlll dp;
int n, s, e;

int main() {
  cin >> n >> s >> e;
  x.assign(n+1, 0);
  a.assign(n+1, 0);
  b.assign(n+1, 0);
  c.assign(n+1, 0);
  d.assign(n+1, 0);
  for (int i = 1; i <= n; ++i) cin >> x[i];
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  for (int i = 1; i <= n; ++i) cin >> c[i];
  for (int i = 1; i <= n; ++i) cin >> d[i];

  dp.assign(n+3, vll(n+3, vl(n+3, 0)));
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      for (int k = 0; k <= i; ++k) {
	ll ans = (1ll<<62);
	if (i == e) {
	  // Case 1: u -> e. Where u > e.
	  if (i < n && j-1 >= 0 && i-1 >= j-1 && i-1 >= k)
	    ans = dp[i-1][j-1][k] - x[i] + b[i];
	  // Case 2: u -> e. Where u < e.
	  if (i > 1 && k+1 <= n  && i-1 >= j && i-1 >= k+1)
	    ans = min(ans, dp[i-1][j][k+1] + x[i] + a[i]);
	  //cout << "In e" << endl;
	  //printf("%d %d %d: %lld\n", i, j, k, ans);
	  dp[i][j][k] = ans;
	} else if (i == s) {
	  // Case 1: s -> u. Where u > s.
	  if (i < n && k-1 >= 0 && i-1 >= j && i-1 >= k-1)
	    ans = dp[i-1][j][k-1] + d[i] - x[i];
	  // Case 2: s -> u. Where u < s.
	  if (i > 1 && j+1 <= n && i-1 >= j+1 && i-1 >= k)
	    ans = min(ans, dp[i-1][j+1][k] + c[i] + x[i]);
	  //cout << "In s" << endl;
	  //printf("%d %d %d: %lld\n", i, j, k, ans);
	  dp[i][j][k] = ans;
	} else {
	  // Case 1: u->i->v. Where u < i < v.
	  //if (k && i > 1 && i < n && i-1 >= j && i-1 >= k)
	  if (k)
	    ans = dp[i-1][j][k] + a[i] + d[i];
	  // Case 2: u<-i<-v. Where u < i < v.
	  //if (j && i > 1 && i < n && i-1 >= j && i-1 >= k)
	  if (j)
	    ans = min(ans, dp[i-1][j][k] + c[i] + b[i]);
	  // Case 3: u->i->v. Where u < i, i > v.
	  //if (i > 2 && j < n && k < n && i-1 >= k+1 && i-1 >= j+1)
	    ans = min(ans, dp[i-1][j+1][k+1] + 2*x[i] + a[i] + c[i]);
	  // Case 4: u->i->v. Where u > i, i < v.
	  //if (i <= n-2 && j > 0 && k > 0 && i-1 >= j-1 && i-1 >= k-1)
	  if (j && k)
	    ans = min(ans, dp[i-1][j-1][k-1] - 2*x[i] + b[i] + d[i]);
	  //cout << "else" << endl;
	  //printf("%d %d %d: %lld\n", i, j, k, ans);
	  dp[i][j][k] = ans;
	}
      }
    }
  }
  cout << dp[n][0][0] << '\n';
}
