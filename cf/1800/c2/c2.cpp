#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef priority_queue<int> pq;

int32_t main() {
  int t; cin >> t;
  while(t--) {
    pq p;
    int n;
    int ans = 0;
    int s;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> s;
      if (s == 0) {
	if (!p.empty()) {
	  ans += p.top(); p.pop();
	}
      } else {
	p.push(s);
      }
    }
    cout << ans << endl;
  }
}
