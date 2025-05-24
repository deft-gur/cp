#include <bits/stdc++.h>

#define int unsigned long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int32_t main() {
  int n, x, d; cin >> n >> d >> x;
  vi k, c;
  k.assign(n, 0);
  c.assign(n, 0);
  for (int i = 0; i < n; ++i) cin >> k[i];
  for (int i = 0; i < n; ++i) cin >> c[i];

  vii a;
  a.assign(n, {0, 0});
  for (int i = 0; i < n; ++i)  {
    a[i].first = c[i];
    a[i].second = min(k[i], d);
  }

  sort(a.begin(), a.end(), greater<>());
  int j = 0;
  int ans = 0;
  int cap = LLONG_MAX;
  for (int i = 0; i < x; ++i) {
    int left = d;
    while(left > 0 && j < n) {
      int sub = min(left, a[j].second);
      ans += a[j].first * sub;
      left -= sub;
      a[j].second -= sub;
      //cap = left - sub;
      if (a[j].second == 0 || cap == 0) { ++j; cap=LLONG_MAX; }
      if (left == 0) break;
    }
  }
  cout << ans << endl;
}
