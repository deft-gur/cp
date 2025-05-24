#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m, p, q;
  cin >> n >> m >> p >> q;

  int quot = n/p;
  int rem = n % p;
  if (rem == 0 && (quot * q) != m) {
    cout << "no" << endl;
  } else {
    cout << "yes" << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
