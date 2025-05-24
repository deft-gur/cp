#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef vector<int> vi;

int32_t main() {
  int n, m;
  cin >> n >> m;
  vi a;
  a.assign(n+1, 0);
  for (int i = 1; i <= n; ++i) {
    int tmp;
    cin >> tmp;
    a[i] += a[i-1] + tmp;
  }
  for (int i = 0; i < m; ++i) {
    int tar; cin >> tar;
    int j = lower_bound(a.begin(), a.end(), tar)- a.begin();
    if (j == n+1) cout << -1 << endl;
    else cout << j << endl;
  }
}
