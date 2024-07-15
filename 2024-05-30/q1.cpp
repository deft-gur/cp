#include <bits/stdc++.h>

using namespace std;

void solve() {
  char c;
  int n;
  cin >> n;
  int ans = true;
  bool sL = false;
  char lastC = 'a';
  char lastD = '0';
  for (int i = 0; i < n; ++i) {
    cin >> c;
    if ('a' <= c && c <='z') {
      sL = true;
      if (c < lastC) ans = false;
      lastC = c;
    } else if ('0' <= c && c <= '9') {
      if (c < lastD || sL) ans = false;
      lastD = c;
    }
  }
  cout << (ans ? "YES" : "NO") << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
