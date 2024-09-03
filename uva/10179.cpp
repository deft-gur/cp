#include <bits/stdc++.h>

using namespace std;

#define int long long 

const int mod = 131071;

int binpow(int b, int q) {
  int a = b;
  int res = 1;
  while(q) {
    if (q % 2) res = (a * res) % mod;
    a = (a * a) % mod;
    q = q >> 1;
  }
  return res;
}

int32_t main() {
  char s;
  int ans = 0;
  while(cin >> s) {
    if (s != '#') ans = ((ans << 1) + s - '0')%mod;
    else {
      cout << (ans == 0 ? "YES" : "NO") << endl;
      ans = 0;
    }
  }
}
