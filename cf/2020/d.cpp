#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int C = 11;

struct UF {
  int size, comp;
  vi p;

  UF(int n) {
    size = comp = n;
    p.assign(n, 0);
    for (int i = 0; i < n; ++i) p[i] = i;
  }

  int set(int i) {
    return (i == p[i] ? i : p[i] = set(p[i]));
  }

  bool sameSet(int i, int j) {
    return set(i) == set(j);
  }

  int compNum() { return comp; }

  void Union(int i, int j) {
    if (sameSet(i, j)) return;
    --comp;
    //cout << "comp" << comp << '\n';
    int x = p[i];
    int y = p[j];
    if (x > y) swap(x, y);
    p[y] = x;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  UF U(n+1);
  vvi dp, ind, start, end;
  dp.assign(n+1, vi(C, 0));
  ind.assign(n+1, vi(C, 0));
  start.assign(n+1, vi(C, 0));
  end.assign(n+1, vi(C, 0));

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < C; ++j) {
      ind[i][j] = i;
    }
  }

  for (int i = 0; i < m; ++i) {
    int a, d, k;
    cin >> a >> d >> k;
    ++start[a][d];
    ++end[a + k*d][d];
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < C; ++j) {
      dp[i][j] = start[i][j] - end[i][j];
      if (i <= j) continue;
      if (dp[i-j][j]) {
	U.Union(ind[i-j][j], i);
	ind[i][j] = ind[i-j][j];
	dp[i][j] += dp[i-j][j];
      }
    }
  }

  cout << U.compNum() - 1 << '\n';
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}
