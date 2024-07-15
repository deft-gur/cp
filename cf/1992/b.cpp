#include <bits/stdc++.h>

using namespace std;

void solve() {
  int mx = 0;
  int idx = -1;
  int n, k;
  cin >> n >> k;
  int a[k];
  for (int i = 0; i < k; ++i) {
    cin >> a[i];
    mx = max(mx, a[i]);
    if (mx == a[i]) idx = i;
  }
  int count = 0;
  for (int i = 0; i < k; ++i) {
    if (idx == i) continue;
    count += 2*a[i] - 1;
  }
  cout << count << endl;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}
