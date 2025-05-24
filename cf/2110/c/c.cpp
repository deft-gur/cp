#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
int n;
vi d, hmin, hmax;

void solve() {
  cin >> n;
  d.assign(n, 0);
  hmin.assign(n+1, 0);
  hmax.assign(n+1, 0);
  for (int i = 0; i < n; ++i) { cin >> d[i]; }
  int l, r, a, b;
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    cin >> l >> r;
    if (d[i] == -1) {
      a = hmin[i]; b = hmax[i] + 1;
    } else {
      a = hmin[i] + d[i]; b = hmax[i] + d[i];
    }
    hmin[i+1] = max(l, a); hmax[i+1] = min(b, r);
    if (hmin[i+1] > hmax[i+1]) ans = 0;
  }

  if (ans == 0) { cout << "-1\n"; return; }

  int h = hmax[n];
  for (int i = n-1; i >= 0; --i) {
    if (d[i] == 1) {
      h--;
    } else if (d[i] == -1) {
      if (h - 1 >= hmin[i] && h-1 <= hmax[i]) {
	d[i] = 1; --h;
      } else {
	d[i] = 0;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << d[i] << " \n"[(i==n-1 ? 1 : 0)];
  }
}

int main() {
  int t; cin >> t;
  while(t--) {
    solve();
  }
}
