#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

void solve() {
  int n;
  vi a;
  cin >> n;
  a.assign(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  int l = 0, r = n-1;
  for (; l < n; ++l) {
    if (a[l] % 2 == a[n-1] % 2) break;
  }
  for (; r >= 0; --r) {
    if (a[r] % 2 == a[0] % 2) break;
  }

  cout << min(n-1 - r, l) << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
