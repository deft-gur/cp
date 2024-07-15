#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int a[n][n];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> a[i][j];

  int ans[n*n];
  for (int i = 0; i < n; ++i) {
    if (i & 1) {
      for (int j = 0; j < n; ++j) ans[i*n + j] = a[j][i];
    } else {
      for (int j = n-1; j >= 0; --j) ans[i*n + (n - j - 1)] = a[j][i];
    }
  }

  int happy = 0;
  int sad = 0;

  for (int i = 0; i < n * n - 1; ++i) {
    if (ans[i] < ans[i+1]) ++sad;
    else ++happy;
  }

  if (happy < sad) reverse(ans, ans + n*n);

  for (int i = 0; i < n * n; ++i) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << "\n";
}

int main() {
  int t;
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) solve();
}
