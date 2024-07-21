#include <bits/stdc++.h>

using namespace std;

#define M 45
#define MX 1005
int m;
int previous[MX][M];
int minH[MX][M];
int h[M];

void dp(int curH, int maxH, int prevH, int d) {
  if (curH < 0) return;
  int &resPrev = previous[curH][d];
  int &resH = minH[curH][d];

  if (resH == -1){
    resH = maxH;
    resPrev = prevH;
  } else {
    if (resH <= maxH) return;
    resH = maxH;
    resPrev = prevH;
  }

  if (d == m) return;

  dp(curH + h[d+1], max(curH + h[d+1], maxH), curH, d+1);
  dp(curH - h[d+1], maxH, curH, d+1);
}

void solve() {
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> h[i];
  }
  memset(previous, -1, sizeof previous);
  memset(minH, -1, sizeof minH);

  dp(0, 0, 0, 0);
  if (previous[0][m] == -1){
    cout << "IMPOSSIBLE" << endl;
    return;
  } 
  string ans = "";
  int curH = 0;
  for (int i = m; i > 0; --i) {
    int pH = previous[curH][i];
    if (pH > curH) ans += 'D';
    else ans += 'U';
    curH = pH;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
