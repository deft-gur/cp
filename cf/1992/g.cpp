#include <bits/stdc++.h>

using namespace std;

#define MX 5001
#define int long long

const int mod = 1e9 + 7;

int f[MX];
int r[MX];

int add(int x, int y) {
  return (x + y) % mod;
}

int mult(int x, int y) {
  x = x % mod;
  y = y % mod;
  return (x * y) % mod;
}

int binpow(int x, int n) {
  int a = x;
  int res = 1;
  while(n) {
    if (n % 2) res = mult(res, a);
    n >>= 1;
    a = mult(a, a);
  }
  return res;
}

void init() {
  f[0] = 1, r[0] = 1;
  for (int i = 1; i < MX; ++i) {
    f[i] = mult(f[i-1], i);
    r[i] = binpow(f[i], mod - 2);
  }
}

int C(int n, int k) {
  return mult(mult(f[n], r[k]), r[n-k]);
}

void solve() {
  int n;
  cin >> n;
  int res = 0;
  for (int i = 0; i <= n; ++i) {
    if (2*i >= n) {
      res = add(res, mult(C(n, i), 2*i+1));
      continue;
    }
    for (int m = i+1; m <= 2 * i + 1; ++m) {
      res = add(res, mult(m, mult(C(m-1, m-i-1), C(n-m, 2*i-m+1))));
    }
  }
  cout << res << endl;
}

int32_t main() {
  int t;
  cin >> t;
  init();
  while (t--) solve();
}
