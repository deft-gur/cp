#include <bits/stdc++.h>

using namespace std;
#define MX 200005
int n;
int a[MX];
int dp[MX];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];

  dp[0] = 0;
  bool filled[2] = {false, false};
  for (int i = 1; i <= n; ++i) {
    int &res = dp[i];
    res = dp[i-1] + 1;
    if (a[i] <= 0) {
      res = min(dp[i-1], res);
      filled[0] = filled[1] = false;
    } else if(a[i] <= 2) {
      if (filled[0]) {
	filled[0] = false;
	res = dp[i-1];
      }
      else filled[0] = true;
      filled[1] = false;
    }
    if (2 < a[i] && a[i] < 5) {
      if (filled[0] || filled[1]) {
        filled[0] = !filled[0];
        filled[1] = !filled[1];
      }
    }
    if (a[i] > 4) filled[0] = filled[1] = false;
  }
  cout << dp[n] << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
