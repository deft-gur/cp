#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int a[n], b[n];
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  int bob = false;
  int same = 0;
  for (int i = 0; i < n; ++i) { if (a[i] == b[i]) ++same; }
  if (same == n) bob = true;
  reverse(b, b+n);
  same = 0;
  for (int i = 0; i < n; ++i) { if (a[i] == b[i]) ++same; }
  if (same == n) bob = true;
  cout << (bob ? "Bob" : "Alice") << '\n';
}


int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
