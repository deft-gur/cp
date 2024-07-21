#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, x, y;
  cin >> n >> x >> y;

  bool one;
  one = ((y-1) % 2 == 0);
  for (int i = 1; i <= n; ++i) {
    if (i < y || i > x) {
      cout << (one ? 1 : -1) << " ";
      one = !one;
    } else if (i >= y && i <= x) {
      cout << 1 << " ";
    }
    if (i == x) {
      one = false;
    }
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
