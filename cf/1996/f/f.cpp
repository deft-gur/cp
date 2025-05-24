#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef vector<int> vi;
vi a, b;
int n, k;

void solve() {
  cin >> n >>k;
  a.assign(n, 0), b.assign(n, 0);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  int l, r;
  int m;
  l = 0; r = *max_element(a.begin(), a.end()) + 1;
  while(l < r) {
    int m = (l+r)/2;
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] >= m) {
	res += (a[i] - m)/b[i] + 1;
      }
    }
    if (res <= k) {
      r = m;
    } else {
      l = m+1;
    }
  }

  long long ans = 0;
  int used = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] >= l) {
      int m = (a[i] - l)/b[i];
      ans += (long long)((m+1)*a[i]) - (long long)((m*(m+1))/2*b[i]);
      a[i] -= (m+1) * b[i];
      used += m+1;
    }
  }
  sort(a.begin(), a.end(), greater<int>());
  for (int i = 0; i < k - used; ++i) {
    if (i >= n) break;
    if (a[i] > 0) ans += 1ll * a[i];
  }
  cout << ans << endl;
}

int32_t main() {
  int t;
  cin >> t;
  while(t--) solve();
}
