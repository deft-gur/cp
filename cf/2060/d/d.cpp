#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
vi a;
int n;

void solve() {
  cin >> n;
  a.assign(n, 0);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n-1; ++i) {
    int tmp = min(a[i], a[i+1]);
    a[i] -= tmp;
    a[i+1] -= tmp;
  }

  int ans = 1;
  for (int i = 0; i < n-1; ++i) {
    if (a[i] > a[i+1]) ans = 0;
  }
  cout << (ans == 1 ? "YES" : "NO") << '\n';
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}
