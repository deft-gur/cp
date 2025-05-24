#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n;
vi a, b;
vii c;

int32_t main() {
  cin >> n;
  a.assign(n, 0), b.assign(n, 0), c.assign(n, {0, 0});
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    c[i].first = a[i] - b[i];
    c[i].second = i;
  }
  sort(c.begin(), c.end(), greater<ii>());
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int j = c[i].second;
    ans += b[j]*n - a[j] + (i+1) * (c[i].first);
  }
  cout << ans << endl;
}
