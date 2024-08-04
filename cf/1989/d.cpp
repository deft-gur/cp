#include <bits/stdc++.h>

using namespace std;
#define ll long long

int32_t main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int a[n];
  int b[n];
  ll c[m];

  for (int i = 0; i < n; ++i) { cin >> a[i]; }
  for (int i = 0; i < n; ++i) { cin >> b[i]; }
  for (int i = 0; i < m; ++i) { cin >> c[i]; }


  int mx = *max_element(a, a + n);
  vector<int> best;
  ll calc[mx+1];
  memset(calc, 0, sizeof calc);
  best.assign(mx + 1, 1e6);

  for (int i = 0; i < n; ++i) {
    best[a[i]] = min(best[a[i]], a[i] - b[i]);
  }

  for (int i = 1; i <= mx; ++i) {
    best[i] = min(best[i-1], best[i]);
  }

  for (int i = 1; i <= mx; ++i) {
    if (i >= best[i]) calc[i] = 2 + calc[i - best[i]];
  }

  ll ans = 0;
  for (int i = 0; i < m; ++i) {
    ll val = c[i];
    if (val > mx) {
      ll k = (val - mx + best[mx])/best[mx];
      ans += 2 * k;
      val -= best[mx] * k;
    }
    ans += calc[val];
  }
  cout << ans << endl;

  return 0;
}
