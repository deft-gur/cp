#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  int g = 360;
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    g = __gcd(g, tmp);
  }
  for (int i = 0; i < k; ++i) {
    int tmp;
    cin >> tmp;
    cout << (tmp % g == 0 ? "YES" : "NO") << endl;
  }
}

int main() {
  int t;
  solve();
}
