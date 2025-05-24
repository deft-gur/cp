#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef vector<int> vi;
typedef vector<vi> vvi;
vvi grid;
vi moves, sumRow, sumCol;
int n, m;

void solve() {
  cin >> n >> m;
  grid.assign(n, vi(m, 0));
  moves.assign(n+m-2, 0);
  sumRow.assign(n, 0);
  sumCol.assign(m, 0);

  for (int i = 0; i < n+m-2; ++i) {
    char c; cin >> c;
    if (c == 'D') moves[i] = 0;
    else moves[i] = 1;
  }


  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    cin >> grid[i][j];
    sumRow[i] += grid[i][j];
    sumCol[j] += grid[i][j];
  }

  int i = 0, j = 0;
  for(int k = 0; k < n+m-2; ++k) {
    //cout << "k" << k << endl;
    if (moves[k] == 0) {
      int tmp = grid[i][j];
      //cout << sumRow[i] - grid[i][j] << endl;
      grid[i][j] = -(sumRow[i] - grid[i][j]);
      sumRow[i] = sumRow[i] - tmp + grid[i][j];
      sumCol[j] = sumCol[j] - tmp + grid[i][j];
      ++i;
    } else {
      int tmp = grid[i][j];
      grid[i][j] = -(sumCol[j] - grid[i][j]);
      //cout << sumCol[i] - grid[i][j] << endl;
      sumRow[i] = sumRow[i] - tmp + grid[i][j];
      sumCol[j] = sumCol[j] - tmp + grid[i][j];
      ++j;
    }
  }
  grid[n-1][m-1] = -(sumRow[i] - grid[i][j]);

  for (i = 0; i < n; ++i) { 
    for (j = 0; j < m; ++j) cout << grid[i][j] << ' ';
    cout << '\n';
  }
}

int32_t main() {
  int t;
  cin >> t;
  while(t--) solve();
}
