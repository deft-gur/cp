#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  if (k == 2) {
    cout << n - 1 << endl;
    return;
  }
  int q = n/(k-1);
  int r = n %(k-1);
  if (r > 1) ++q;
  cout << q << endl;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}
