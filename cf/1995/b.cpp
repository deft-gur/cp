#include <bits/stdc++.h>

#define int long long

using namespace std;
int a[200005];
int n, m;


void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  map<int, int> count;
  for (int i = 0; i < n; ++i) {
    ++count[a[i]];
  }
  int ans = 0;
  for (auto [k, v] : count) {
    auto it = count.find(k+1);
    int c = (it != count.end()) ? it->second : 0;
    for (int i = 0; i <= v; ++i) {
      if (i * k <= m) {
	int x = min((m-k*i)/(k+1), c);
	ans = max(ans, k * i + (k+1) * x);
      } else break;
    }
  }
  cout << ans << endl;
}

int32_t main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}
