#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  int i = 0;
  int l = n;
  if (k > 0) {
    ++i;
    k -= n;
  }
  --l;
  bool change = false;
  while(k > 0) {
    k -= l;
    ++i;
    if (change) --l;
    change = !change;
  }
  cout << i << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
