#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define ith(x, y) (x >> y)&1ll

void solve() {
  ll b, c, d;
  cin >> b >> c >> d;
  ll a = 0;
  // find (a|b) - (a&c) = d

  bool possible = true;
  // clzll does not accept 0.
  //int lz = __builtin_clzll(d);
  //int end = 62 - lz;
  int end = 62;
  for (int i = 0; i < end; ++i) {
    int bitD = ith(d, i);
    int bitB = ith(b, i);
    int bitC = ith(c, i);
    if (bitB == bitD) {
    } else {
      if (bitD == 1 && bitC == 0) a += 1ll << i;
      else if (bitD == 0 && bitC == 1) a+= 1ll << i;
      else {possible = false; break; }
      //else if (bitD == 0 && bitC == 0) {possible=false; break;}
      //else if (bitD == 1 && bitC == 1) { possible = false; break; }
    }
  }

  cout << (possible ? a : -1) << '\n';
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
