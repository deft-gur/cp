// Incomplete and incorrect soln.
#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
int n, k, l;
vi a;

void solve() {
  cin >> n >> k >> l;
  a.assign(n, 0);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int start = k;
  int mx = a[0];
  a[0] = 0;
  for (int i = 1; i < n; ++i) {
    int oldStart = start;
    start += k;
    if (a[i] <= oldStart && oldStart - a[i] < k) continue;
    if (a[i] > oldStart) mx = max(mx, a[i] - oldStart - k + 1);
    else mx = max(mx, oldStart + k - a[i] - 1);
  }
  cout << mx << '\n';
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
