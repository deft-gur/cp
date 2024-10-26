#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int n, m;
vvi pref, suf, dpL, dpR, A;

void solve() {
  cin >> n >> m;
  A.assign(n, vi(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> A[i][j];
    }
  }
  pref.assign(n, vi(m+1, 0));
  suf.assign(n, vi(m+1, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= m; ++j) {
      pref[i][j] = pref[i][j-1] + A[i][j];
    }
    for (int j = m-1; j >= 0; ++j) {
      pref[i][j] = pref[i][j+1] + A[i][j];
    }
  }

  for (int l = 0; l <= m; ++l) {
    for (int r = l; r <= m; ++r) {
      dpL[0][l] = max(dpL[0][l], pref[0][r] - pref[0][l]);
      dpR[0][r] = max(dpR[0][r], pref[0][r] - pref[0][l]);
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int l = 0; l <= m; ++l) {
      for (int r = l; r<= m; ++r) {
	int mx = 0;
	for (int p = l; p <= r; ++p) {
	  if (p == l) { mx = max(dpR[i-1][p], mx); }
	  else if (p == r) { mx = max(dpL[i-1][p], mx); } 
	  else { mx = max(dpL[i-1][p], dpR[i-1][p], mx); }
	}
	mx += pref[i][r] - pref[i][l];
	dpL[i][l] = max(mx, dpL[i][l]);
	dpR[i][r] = max(mx, dpR[i][r]);
      }
    }
  }

  int mx = 0;
  for (int i = 0; i <= m; ++i) {
    mx = max(dpL[n][i], dpR[n][i], mx);
  }
  cout << mx << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
