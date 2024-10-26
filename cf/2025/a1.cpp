#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s, t;
  cin >> s >> t;
  int total = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == t[i]) ++total;
    else break;
  }
  cout << (total ? (s.size() + t.size() - total + 1) : s.size() + t.size()) << '\n';
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
