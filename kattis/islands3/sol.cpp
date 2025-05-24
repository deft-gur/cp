#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n, m, islands;
vvi grid, visited;

void floodFill(int i, int j) {
  if (i < 0 || i >= n || j < 0 || j >= m) return;
  if (visited[i][j] || grid[i][j] == 0) return;
  //if (gird[i][j] == 2) grid[i][j] = 1;
  visited[i][j] = 1;
  floodFill(i-1, j);
  floodFill(i+1, j);
  floodFill(i, j-1);
  floodFill(i, j+1);
}

int main() {
  cin >> n >> m;
  grid.assign(n, vi(m, 0));
  visited.assign(n, vi(m, 0));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c; cin >> c;
      if (c == 'L') grid[i][j] = 1;
      if (c == 'C') grid[i][j] = 2;
    }
  }
  islands = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!visited[i][j] && grid[i][j] == 1) {
	floodFill(i, j);
	++islands;
      }
    }
  }
  cout << islands << '\n';
}
