#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int SIZE = 100000 + 1;

void solve() {
  int t;
  cin >> t;
  int n, k, q;
  vector<int> a(SIZE);
  vector<int> b(SIZE);
  a[0] = 0; b[0] = 0;
  for (int i = 0; i < t; ++i) {
    cin >> n >> k >> q;
    for (int i = 1; i <= k; ++i) cin >> a[i];
    for (int i = 1; i <= k; ++i) cin >> b[i];
    for (int i = 0; i < q; ++i) {
      if (i > 0) cout << " ";
      int pt;
      cin >> pt;
      auto it = lower_bound(a.begin() + 1, a.begin() + k + 1, pt);
      long long idx = it - a.begin();
      long long den = *it - *(it - 1);
      long long num = b[idx] - b[idx -  1];
      long long ans = b[idx - 1] + (pt - *(it - 1)) * num / den;
      cout << ans;
    }
    cout << endl;
  }
}

int main() {
  solve();
}
