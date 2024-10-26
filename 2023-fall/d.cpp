#include <bits/stdc++.h>

using namespace std;

int main() {
  int r, g, b, k;
  cin >> r >> g >> b >> k;
  if ((g - b) % (k+3)) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";

  vector<pair<char, char>> res;

  while (g || b) {
    if (res.size() > 1e5) return 0;

    if (g == 0) {
      g += 2 + k;
      --r; --b;
      res.emplace_back('R', 'B');
    }

    if (b == 0) {
      b += 2 + k;
      --r; --g;
      res.emplace_back('R', 'G');
    }

    if (g && b) {
      --g; --b;
      r += 2 + k;
      res.emplace_back('B', 'G');
    }

  }

  cout << res.size() << '\n';
  for (auto p : res) {
    cout << p.first << ' ' << p.second << '\n';
  }

}
