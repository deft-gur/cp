#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  char f;
  int a, b, c, d, e;
  a = b = c = d = e = 0;
  for (int i = 0; i < 4*n; ++i) {
    cin >> f;
    if (f == 'A') ++a;
    else if (f == 'B') ++b;
    else if (f == 'C') ++c;
    else if (f == 'D') ++d;
    else ++e;
  }
  int ans = 0;
  ans += min(n, a) + min(n, b) + min(n, c) + min(n, d);
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
