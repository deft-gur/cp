#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int t, n;
const int N = 1e5;
vi a;
vvi b, pref, prefA;

void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= 10; ++j) {
      b[j][i] = 0;
      if (a[i] < j) b[j][i] = -1;
      else if (a[i] > j) b[j][i] = 1;
      if (a[i] == j) prefA[j][i+1] = prefA[j][i] + 1;
      else prefA[j][i+1] = prefA[j][i];
      pref[j][i+1] = pref[j][i] + b[j][i];
    }
  }

  int bad = 0;
  for (int l = 0; l < n; ++l) {
    for (int r = l+1; r < n; r+=2) {
      int isBad = 1;
      for (int j = 1; j <= 10; ++j) {
	int numOfJ = prefA[j][r+1] - prefA[j][l] - 2;
	if (numOfJ < -1) continue;
	if (abs(pref[j][r+1] - pref[j][l]) <= numOfJ) { 
	  isBad = 0; break; 
	}
      }
      bad += isBad;
    }
  }
  cout << n*(n-1)/2 + n - bad << '\n';
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> t;
  a.assign(N, 0);
  b.assign(11, vi(N, 0));
  pref.assign(11, vi(N+1, 0));
  prefA.assign(11, vi(N+1, 0));
  while(t--) {
    solve();
  }
}
