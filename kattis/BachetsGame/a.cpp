#include <bits/stdc++.h>

using namespace std;
int n;
int m;
int a[10];
int memo[1000005];

int wins(int h, int s) {
  memset(memo, 0, sizeof memo);
  memo[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i >= a[j]) {
	if (memo[i - a[j]] == 0) memo[i] = 1;
      }
    }
  }
  return memo[n];
}

void solve() {
  memset(memo, -1, sizeof memo);
  for (int i = 0; i < m; ++i) cin >> a[i];
  sort(a, a+m);

  int w = wins(0, n);
  cout << (w ? "Stan" : "Ollie") << " wins\n";
}

int main() {
  while (cin >> n >> m) solve();
}
