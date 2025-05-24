#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef pair<int, int> ii;
typedef map<ii, double> IItoI;

IItoI multiplier = {
  {{0, 0}, 1},   {{0, 1}, 0.5}, {{0, 2}, 2},
  {{1, 0}, 2},   {{1, 1}, 1},   {{1, 2}, 0.5},
  {{2, 0}, 0.5}, {{2, 1}, 2},   {{2, 2}, 1}
};

int typeToInt(string s) {
  if (s == "FIRE") {
    return 0;
  } else if (s == "WATER") {
    return 1;
  } else {
    return 2;
  }
}

int32_t main() {
  int n;
  string t;
  cin >> t >> n;
  int E = typeToInt(t);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x; string y;
    cin >> x >> y;
    int F = typeToInt(y);
    ans = max(ans, (int)(x * multiplier[{F, E}]));
  }
  cout << ans << endl;
}
