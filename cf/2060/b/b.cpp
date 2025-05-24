#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<int, int> mii;

int n, m;
vvi cards;
mii perm;

void solve() {
  cin >> n >> m;
  cards.assign(n, vi(m, 0));
  perm.clear();
  int exist = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> cards[i][j];
      if (cards[i][j] < n && perm.find(cards[i][j]) != perm.end()) {
	exist = 0;
      } else if (cards[i][j] < n) perm[cards[i][j]] = i;
    }
  }

  for (int i = 0; i < n; ++i) {
    sort(cards[i].begin(), cards[i].end());
  }

  for (int i = 0; i < n; ++i) {
    if (exist == 0) break;
    for (int j = 0; j < m; ++j) {
      //printf("%d %d %d: %d %d\n", i, perm[i], j, cards[perm[i]][j], j*n+i);
      if (cards[perm[i]][j] != j*n + i) { exist = 0; break;}
    }
  }

  if (exist == 0) { cout << "-1 \n"; return; }

  for (int i = 0; i < n; ++i) {
    cout << perm[i]+1 << " ";
  }
  cout << '\n'; return;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
