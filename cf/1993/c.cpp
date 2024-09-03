#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  int a[n];
  int d[2*k];
  memset(d, 0, sizeof d);
  int mod = 2*k;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int mx = *max_element(a, a+n);
  for (int i = 0; i < n; ++i) {
    ++d[a[i] % mod];
  }

  int cnt = 0;
  for (int i = 0; i <= k-2; ++i) {
    cnt += d[i];
  }

  int ans = INT_MAX;
  for (int l = 0, r = k-1; l < 2*k; ++l, ++r) {
    if (r == 2*k) r = 0;

    cnt += d[r];
    if (cnt == n) {
      int x = (((r - mx) % mod) + mod) % mod;
      ans = min(ans, mx + x);
    }
    cnt -= d[l];
  }

  if (ans == INT_MAX) ans = -1;
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
