#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
  int n, m;
  cin >> n >> m;
  vi str, intl, x;
  vvi dp;
  str.assign(m+1, 0);
  intl.assign(m+1, 0);
  dp.assign(m+1, vi(m+1, 0));
  x.assign(n+1, 0);

  for (int i = 0; i < n; ++i) {
    cin >> x[i];
    if (x[i] > 0) intl[x[i]]++;
    if (x[i] < 0) str[-x[i]]++;
  }

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (x[i] > 0) intl[x[i]]--;
    if (x[i] < 0) str[-x[i]]--;
    if (x[i] == 0) {
      ++cnt;
      for (int j = 0; j <= cnt; ++j) {
	if (j == 0) {
	  dp[0][cnt] = dp[0][cnt-1] + intl[cnt];
	} else if (j == cnt) {
	  dp[j][0] = dp[j-1][0] + str[j];
	} else {
	  dp[j][cnt-j] = max(dp[j-1][cnt-j] + str[j], dp[j][cnt-j-1] + intl[cnt-j]);
	}
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j <= m; ++j) {
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << '\n';
}
