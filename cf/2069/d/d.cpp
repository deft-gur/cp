#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
string s;
vi cnt;


void solve() {
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n/2; ++i) {
    if (s[i] != s[n-i-1]) {
      n = n - 2*(i);
      s = s.substr(i, n);
      break;
    }
  }

  int ans = n;
  for (int z = 0; z < 2; ++z) {
    int l, r; l = 0; r = n;
    while(l < r) {
      int m = (l+r)/2;
      cnt.assign(26, 0);
      for (int i = 0; i < m; ++i) {
	++cnt[s[i] - 'a'];
      }
      bool ok = true;
      for (int i = 0; i < n - m; ++i) {
	int c = s[n-i-1] - 'a';
	if (i < m) {
	  ok &= (cnt[c] > 0);
	  --cnt[c];
	} else {
	  ok &= (s[n-i-1] == s[i]);
	}
      }
      for (auto x : cnt) {
	ok &= (x%2 == 0);
      }

      if (ok) r = m;
      else l = m+1;
    }
    ans = min(ans, l);
    reverse(s.begin(), s.end());
  }

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
