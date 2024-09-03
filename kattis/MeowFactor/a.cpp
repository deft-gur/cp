#include <bits/stdc++.h>

using namespace std;

// NOTE: 2^63 - 1 = 128^9
#define int unsigned long long
#define MX 128
#define EPS 1e-6
#define LARGE 0b111111111111111111111111111111111111111111111111111111111111111

int binpow(int a, int b) {
  int ans = 1;
  while(b) {
    if (b % 2) ans *= a;
    a *= a;
    b = b >> 1;
  }
  return ans;
}

int32_t main() {
  int a;
  cin >> a;
  int ans = 1;
  for (int i = 2; i <= MX; ++i) {
    if (a % binpow(i, 9) == 0) ans = i;
  }
  cout << ans << '\n';
}

