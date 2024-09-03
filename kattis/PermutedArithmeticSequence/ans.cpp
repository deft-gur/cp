#include <bits/stdc++.h>

using namespace std;

int a[101];
int n;

bool sorted(bool asc = true) {
  for (int i = 0; i < n-1; ++i) {
    if (asc && a[i] > a[i+1]) return false;
    if (!asc && a[i] < a[i+1]) return false;
  }
  return true;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  bool f = sorted(true) || sorted(false);
  sort(a, a+n);
  bool arith = true;
  int diff = a[1] - a[0];
  for (int i = 1; i < n-1; ++i) {
    if (a[i+1] - a[i] != diff) { arith = false; break; }
  }
  if (f && arith) cout << "arithmetic";
  else if (!f && arith) cout << "permuted arithmetic";
  else cout << "non-arithmetic";
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
