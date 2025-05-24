#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n, q;
  cin >> n;
  vector<char> a;
  a.assign(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  cin >> q;
  vi used;
  while(q--) {
    int m; char c;
    cin >> m >> c;
    used.assign(n, 0);
    int l = 0, r = 0;
    int ans = 0;
    while(r < n && l < n) {
      if (a[r] == c) ++r;
      else if (m) { used[r] = 1; ++r; --m; }
      else if (used[l] == 1) { used[l] = 0; ++l; ++m;}
      else { ++l; }
      ans = max(ans, r-l);
      //printf("l, r: %d, %d\n", l, r);
    }
    cout << ans << '\n';
  }
}
