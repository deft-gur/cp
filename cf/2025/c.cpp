#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
vi a;

void solve() {
  int n, k;
  cin >> n >> k;
  a.assign(n, 0);
  queue<int> q;
  map<int, int> m;
  for (int i = 0; i < n; ++i) { cin >> a[i]; }
  sort(a.begin(), a.end());
  int last = a[0];
  ++m[last];
  q.push(last);
  int total = 1;
  int mx = 1;
  for (int i = 1; i < n; ++i) {
    if (last != a[i]) {
      if (last != a[i]-1) {
	q = queue<int>();
	total = 0;
      } else if (q.size() == k) {
	  int x = q.front(); q.pop();
	  total -= m[x];
      }
      q.push(a[i]);
    }
    ++m[a[i]];
    ++total;
    mx = max(mx, total);
    last = a[i];
  }
  cout << mx << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
