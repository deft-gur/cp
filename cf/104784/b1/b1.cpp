#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
ull mod = 1000000007;

ull binPow(ull a, ull b) {
  if (b < 0) return 0;
  ull tmp = a;
  ull ans = 1;
  while (b) {
    if (b % 2) ans = (ans * tmp) % mod;
    tmp = (tmp*tmp) % mod;
    b = (b >> 1);
  }
  return ans;
}

int main() {
  ull a, b, k, c;
  cin >> a >> b >> k >> c;
  ull count = (k * binPow(2, k-1)) % mod;
  ull ans = 0;
  if (a == c || b == c) ans = count % mod;
  if (a == c && b == c) ans = k;
  cout << ans << endl;
}
