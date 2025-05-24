#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
int t, n, m;
vi x, y;


int main() {
  cin >> t;
  while(t--) {
    cin >> n >> m;
    int x, y;
    int wid = 0, len = 0;
    cin >> x >> y;
    for (int i = 1; i < n; ++i) {
      cin >> x >> y;
      len += y;
      wid += x;
    }
    int ans = 0;
    ans += (len + m) * 2;
    ans += (wid + m) * 2;
    cout << ans << '\n';
  }
}
