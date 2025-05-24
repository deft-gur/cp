#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef map<int, int> mii;
int n, m;
vvi g;
si colors;
mii cnts;

int sameColorNeigh(int i, int j) {
  //cout << i << " " << j << endl;
  if (i > 0 && g[i][j] == g[i-1][j]) return 1;
  else if (i < n-1 && g[i][j] == g[i+1][j]) return 1;
  else if (j > 0 && g[i][j] == g[i][j-1]) return 1;
  else if (j < m-1 && g[i][j] == g[i][j+1]) return 1;
  return 0;
}

void solve() {
  cin >> n >> m;
  g.assign(n, vi(m, 0));
  cnts.clear();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> g[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if(sameColorNeigh(i, j)) {
	cnts[g[i][j]] = max(cnts[g[i][j]],2);
      } else {
	cnts[g[i][j]] = max(cnts[g[i][j]],1);
      }
    }
  }

  int ans = 0;
  int mx = 0;
  for (auto [k, v] : cnts) {
    ans += v;
    mx = max(v, mx);
  }

  cout << ans-mx << endl;
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}
