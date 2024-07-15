#include  <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  string s;
  cin >> s;
  s = "L" + s + "L";
  n += 2;
  int idx = 0;
  int survive = true;
  int swim = 0;
  //cout << s << n << endl;
  while (idx < n-1) {
    //cout << idx;
    if (!survive) break;
    if (s[idx] == 'L') {
      int next = idx;
      for (int i = 1; i <= m; ++i) {
	if (s[idx + i] == 'L') {
	  next = idx + i;
	  break;
	} else if (s[idx + i] == 'W'){
	  next = idx + i;
	}
      }
      if (idx == next) survive = false;
      idx = next;
    } else if (s[idx] == 'W') {
      ++swim;
      ++idx;
      if (swim > k) survive = false;
    } else {
      survive = false;
    }
  }

  cout << (survive ? "YES" : "NO") << endl;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}
