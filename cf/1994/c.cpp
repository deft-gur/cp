#include <bits/stdc++.h>

using namespace std;

#define MX 200005
#define int long long

int n, x;
int a[MX];
int preSum[MX];
int dp[MX];

int bin(int l, int r, int p) {
  //cout << "bin: " << l << " " << r << endl;
  if (l == r) {
    if (r == n && preSum[r] - preSum[p-1] <= x) return -1;
    else return l;
  };
  int m = (l + r)/2;
  int sum = preSum[m] - preSum[p - 1];
  //cout << "sum: " << sum << endl;
  if (sum > x) return bin(l, m, p);
  else return bin(m+1, r, p);
}

void solve() {
  memset(dp, 0, sizeof dp);
  memset(preSum, 0, sizeof preSum);

  cin >> n >> x;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  preSum[0] = 0;
  for (int i = 1; i <= n; ++i) {
    preSum[i] = preSum[i-1] + a[i];
  }

  for (int i = n; i > 0; --i) {
    int k = bin(i, n, i);
    //cout << i << " " << k << endl;
    if (k == -1) dp[i] = n - i + 1;
    else dp[i] = dp[k+1] + k - i;
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    //cout << i << " " << dp[i] << endl;
    ans += dp[i];
  }
  cout << ans << endl;
}

int32_t main() {
  int t;
  cin >> t;
  while(t--) solve();
}
