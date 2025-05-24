#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
int n;
vi a;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int odd = 0, even = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      int tmp; cin >> tmp;
      if (tmp % 2) ++odd;
      else ++even;
    }
    if (even > 0) cout << odd + 1 << endl;
    else cout << max(0, odd - 1) << endl;
  }
}
