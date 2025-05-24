#include <bits/stdc++.h>

#define int unsigned long long
using namespace std;
typedef vector<int> vi;
vi a;
vi dp;
int n;
const int mod = 998244353;

int modpow(int x, int y) {
  int a = x;
  int ans = 1;
  while(y) {
    if (y % 2) ans = (ans * a) % mod;
    a = (a * a) % mod;
    y = y >> 1;
  }
  return ans;
}

void solve() {
  cin >> n;
  a.assign(n, 0);
  dp.assign(n, 0);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vi m = { 0 };
  int ones = 0;
  int cur = 0;
  int last3 = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      m.push_back(0);
      ++cur;
    } else if (a[i] == 3) {
      int acc = 0;
      for (auto it = m.rbegin(); it != m.rend(); ++it) {
	acc += *it;
	if (it+1 == m.rend()) { break; }
	dp[i] = (dp[i] + modpow(2, acc) - 1) % mod;
      }
      if (last3 != -1) {
	dp[i] += ones * (modpow(2, acc) - 1);
	dp[i] = dp[i] % mod;
	dp[i] += (dp[last3] * modpow(2, acc)) % mod;
	dp[i] = dp[i] % mod;
      }
      dp[i] = dp[i] % mod;
      ones += cur;
      cur = 0;
      m.clear();
      m.push_back(0);
      last3 = i;
    } else if (a[i] == 2) {
      ++m.back();
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += dp[i];
    ans = ans % mod;
  }
  cout << ans << endl;
}

int32_t main() {
  int t;
  cin >> t;
  while(t--) solve();
}

