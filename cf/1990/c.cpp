#include <bits/stdc++.h>

using namespace std;

#define MX 200005
#define int long long

int n;
int a[MX];
int visited[MX];

void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int sum = 0;
  for (int it = 0; it < 2; ++it) {
    memset(visited, 0, sizeof visited);
    int m = 0;
    for (int i = 0; i < n; ++i) {
      sum += a[i];
      if (visited[a[i]]) {
	m = max(a[i], m);
      }
      visited[a[i]] = 1;
      a[i] = m;
    }
  }

  // Now a[i] are in increasing order and every a[i] must appear at least twice except the zero's infront and last entry.
  for (int i = 0; i < n; ++i) {
    sum += a[i] * (n-i);
  }
  cout << sum << endl;
}

int32_t main() {
  int t;
  cin >> t;
  while(t--) solve();
}
