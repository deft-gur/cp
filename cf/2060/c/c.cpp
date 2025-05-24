#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
int n, k;
vi x;

void solve() {
  cin >> n >> k;
  x.assign(n+1, 0);

  for (int i = 0; i < n; ++i) {
    int tmp; cin >> tmp;
    ++x[tmp];
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (k % 2 == 0 && i == k/2) {
      ans += x[i]/2;
      x[i] -= x[i]/2 * 2;
    } else if (k-i > 0 && k-i <= n) {
      int tmp = min(x[i], x[k-i]);
      //printf("%d %d %d\n", i, x[i], x[k-i]);
      ans += tmp;
      x[i] -= tmp;
      x[k-i] -= tmp;
    }
  }
  cout << ans << '\n';
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
