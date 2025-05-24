#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
vvi grid;

void build(int &acc, int n, int i, int j, int right) {
  if (right) {
    for (int r = i - n; r < i; ++r) {
      grid[r][j] = acc++;
    }
    for (int c = j - n; c < j; ++c) {
      grid[i][c] = acc++;
    }
    grid[i][j] = acc++;
  } else {
    for (int c = j + 1; c <= j + n; ++c) {
      grid[i][c] = acc++;
    }
    for (int r = i + 1; r <= i + n; ++r) {
      grid[r][j] = acc++;
    }
    grid[i][j] = acc++;
  }
}

void init() {
  grid.assign(501, vi(501, 0));
  int acc = 1;
  int i = 250, j = 250;
  for (int n = 1; n <= 500; ++n) {
    if (n % 2 == 1) {
      build(acc, n, i+n/2+1, j+n/2+1, 1);
    } else {
      build(acc, n, i-n/2, j-n/2, 0);
    }
  }
}

void print(int r1, int c1, int r2, int c2) {
  for (int i = r1; i <= r2; ++i) {
    for (int j = c1; j <= c2; ++j) {
      cout << grid[i][j] << " ";
    }
    cout << '\n';
  }
}

void solve() {
  int n;
  cin >> n;
  --n;
  if (n % 2 == 1) {
    print(250-n/2, 250-n/2, 250+n/2+1, 250+n/2+1);
  } else {
    print(250-n/2, 250-n/2, 250+n/2, 250+n/2);
  }
}

int main() {
  int t;
  cin >> t;
  init();
  while(t--) solve();
}
