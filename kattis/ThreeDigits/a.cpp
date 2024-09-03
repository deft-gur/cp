#include <bits/stdc++.h>

using namespace std;

#define int unsigned long long int

const int mod = 1000;

int fact(int n) {
  int ans = 1;
  int fives = 0;
  int twos = 0;
  for (int i = 2; i <= n; ++i) {
    int tmp = i;
    while (tmp % 10 == 0) tmp /= 10;
    while (tmp % 5 == 0) { tmp /= 5; ++fives; }
    while (tmp % 2 == 0) { tmp /=2; ++twos; }
    tmp %= mod;
    ans *= tmp;
    while (ans % 10 == 0) ans /= 10;
    ans = ans % mod;
  }
  int diff = (twos > fives ? twos - fives : fives - twos);
  if (twos > fives) { while (diff--) ans = (ans * 2) % mod; }
  else if (twos < fives) { while (diff--) ans = (ans * 5) % mod; }
  return ans;
}

int32_t main() {
  int n;
  cin >> n;
  int ans = fact(n);
  if (n > 6 && ans < 100) {
    cout << '0';
    if (ans < 10) cout << '0';
  }
  cout << ans << endl;
}
