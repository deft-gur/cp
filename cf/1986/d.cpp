#include <bits/stdc++.h>

using namespace std;

inline int ctoi(char c) {
  return c - '0';
}

void solve() {
  int n; string s;
  cin >> n >> s;
  int m = INT_MAX;
  for (int i = 0; i < n - 1; ++i) {
    int ans = 0;
    bool zero = false;
    for (int j = 0; j < n; ++j) {
      int num = ctoi(s[j]);
      if (i == j) {
	num = ctoi(s[j]) * 10;
	num += ctoi(s[++j]);
      }
      if (num == 0) zero = true;
      if (num == 1) continue;
      ans += num;
    }
    if (zero) ans = 0;
    if (!zero && !ans) ans = 1;
    m = min(ans, m);
  }
  cout << m << endl;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}
