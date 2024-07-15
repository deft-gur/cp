#include <bits/stdc++.h>

using namespace std;

#define MX 10000


void solve() {
  int n;
  cin >> n;
  vector<pair<int,int>> res;
  string s = to_string(n);
  int len = s.size();
  while(s.size() < 8) {
    s += s;
  }

  for (int a = 1; a <= MX; ++a) {
    for (int b = len * a - 1; b >= len * a - 8; --b) {
      if (!(1 <= b && b <= MX)) continue;
      string ans = to_string(n * a - b);
      int c = len * a - b;
      string str = s.substr(0, c);
      if (ans == str) res.emplace_back(a, b);
    }
  }
  cout << res.size() << endl;
  for (auto [x,y] : res) {
    cout << x << " " << y << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) solve();
}
