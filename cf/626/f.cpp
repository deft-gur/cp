#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MOD (int)(1e9+7)
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef tuple<int, int, int> iii;

vii dp;
vi a;
int n, K;

int modMult(int x, int y) {
  return (x * y) % MOD;
}

int modAdd(int x, int y) {
  return (((x + y) % MOD + MOD) % MOD);
}

int32_t main() {
  cin >> n >> K;
  a.assign(n, 0);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  dp.assign(n+1, vi(K+1, 0));

  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    vii newDp; newDp.assign(n+1, vi(K+1, 0));
    for (int j = 0; j <= i; ++j) {
      for (int k = 0; k <= K; ++k) {
	int val = modAdd(k, (i ? a[i] - a[i-1] : 0) * j); 
	if (val > K) continue;
	// Create it's own group and close it. 
	newDp[j][val] = modAdd(newDp[j][val], dp[j][k]);
	// Create it's own group but open.
	newDp[j+1][val] = modAdd(newDp[j+1][val], dp[j][k]);
	// Join another open group but still open.
	newDp[j][val] = modAdd(newDp[j][val], modMult(j, dp[j][k]));
	// Join another group but close it.
	if (j) newDp[j-1][val] = modAdd(newDp[j-1][val], modMult(j, dp[j][k]));
      }
    }
    swap(dp, newDp);
  }

  int ans = 0;
  for (int i = 0; i <= K; ++i) {
    ans = modAdd(ans, dp[0][i]);
  }
  cout << ans << '\n';
}
