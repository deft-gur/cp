#include <bits/stdc++.h>

#define MX 10000
using namespace std;

int n, m, k;
bool A[MX][MX];

void color(int x, int y) {
  return;
  queue<pair<int, int>> q;
  q.emplace(x, y);
  int i, j;
  while(!q.empty()) {
    tie(i, j) = q.front(); q.pop();
    if (A[i][j]) continue;
    A[i][j] = 1;
    if (i + k < n && !A[i+k][j]) q.emplace(i + k, j);
    if (i - k > 0 && !A[i-k][j]) q.emplace(i - k, j);
    if (j + k < m && !A[i][j+k]) q.emplace(i, j + k);
    if (j - k > 0 && !A[i][j-k]) q.emplace(i, j - k);
  }
}

void solve() {
  cin >> n >> m >> k;
  int c = 0;
  c = min(n, k) * min(m, k);
  cout << c << endl;
  return;
  memset(A, 0, sizeof A);
  for (int i = 0; i < min(n, k); ++i) {
    for (int j = 0; j < min(m, k); ++j) {
      if (A[i][j] == 0) { ++c; color(i, j); }
    }
  }
  cout << c << '\n';
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}
