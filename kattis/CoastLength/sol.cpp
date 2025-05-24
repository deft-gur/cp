#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int n, m, length;
vvi grid, visited;

void countLength(int i, int j) {
  //printf("visiting: %d %d %d\n", i, j, grid[i][j]);
  if (i < 0 || i >= n+2 || j < 0 || j >= m+2) return;
  if (visited[i][j] && grid[i][j] == 0) return;
  visited[i][j] = 1;
  if (grid[i][j] == 1) {
    ++length;
    return;
  }
  countLength(i-1, j);
  countLength(i+1, j);
  countLength(i, j-1);
  countLength(i, j+1);
}

int32_t main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  grid.assign(n+2, vi(m+2, 0));
  visited.assign(n+2, vi(m+2, 0));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      char c; cin >> c;
      if (c == '1') grid[i][j] = 1;
    }

  length = 0;
  countLength(0, 0);
  cout << length << '\n';
}
