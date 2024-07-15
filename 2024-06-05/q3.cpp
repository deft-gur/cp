#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int a[n];
  int b[n];
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  int m;
  cin >> m;
  map<int, int> d;
  int last;
  for (int i = 0; i < m; ++i) {
    int tmp;
    cin >> tmp;
    ++d[tmp];
    if (i == m-1) last = tmp;
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) --d[b[i]];
    if (d[b[i]] < 0) {
      cout << "NO" << endl;
      return;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (b[i] == last) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
