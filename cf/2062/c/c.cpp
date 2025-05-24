#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef vector<int> vi;
int n;
vi a;

void solve() {
  cin >> n;
  a.assign(n, 0);
  int ans = 0;
  for (int i = 0; i < n; ++i) { cin >> a[i]; ans += a[i]; }

  for (int i = 1; i < n; ++i) {
    int tmp = 0;
    for (int j = n-1; j >= i; --j) {
      a[j] = a[j] - a[j-1];
      //printf("%d %d\n", j, a[j]);
      tmp += a[j];
    }
    ans = max(ans, tmp);
    ans = max(ans, -tmp);
  }
  cout << ans << endl;
}

int32_t main() {
  int t; cin >> t;
  while(t--) solve();
}
