#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int l = n;
  int r = 1;
  for (int i = 0; i < n; ++i) {
    if (l > m) 
      cout << l-- << " ";
    else
      cout << r++ << " ";
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
