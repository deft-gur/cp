#include <iostream>

using namespace std;

#define BITS 20

void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) cin >> a[i];

  int ans = 1;
  for (int i = 0; i < BITS; ++i) {
    int mx = 1;
    int cnt = 1;
    for (int j = 0; j < n; ++j) {
      if (a[j] & (1 << i)) {
        mx = max(cnt, mx);
        cnt = 1;
      } else {
        ++cnt;
      }
    }
    if (cnt != n+1) mx = max(mx, cnt);
    ans = max(mx, ans);
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
}
