#include <bits/stdc++.h>

using namespace std;

int mostSig(int x) {
  int c;
  while (x >>= 1) {
    ++c;
  }
  return c;
}

void solve() {
  int l, r;
  cin >> l >> r;

  int t;
  if (l) t = 1 << (32 - __builtin_clz(l) -1);
  else t = 1;

  while ((t <<= 1) <= r) {
  }
  cout << __builtin_ctz(t >> 1) << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--)
    solve();
}
