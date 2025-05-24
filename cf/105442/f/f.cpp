#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int n, m;
vvi grid;


int main() {
  cin >> n >> m;
  grid.assign(n, vi(m, 0));
  int ans = 0;
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { cin >> grid[i][j]; ans += grid[i][j]; }

  int a = 0;
  if (n % 2 == 0 && m % 2 == 0) {
    a = 1000;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
	if ((i + j) % 2) a = min(a, grid[i][j]);
      }
    }
  }
  cout << ans - a << endl;
}
