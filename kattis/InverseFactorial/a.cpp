#include <bits/stdc++.h>

using namespace std;

int digits = 0;

int bs(int l, int r) {
  if (l == r) return l;
  int m = (l+r + 1)/2;
  double c = m * log10(m) - m / log(10) + 1;
  if (c > digits) {
    return bs(l, m-1);
  } else {
    return bs(m, r);
  }
}

int main() {
  string s;
  cin >> s;
  digits = s.size();
  if (digits >= 10) {
    cout << bs(1, 1e6) << endl;
  } else {
    long long f = stoll(s);
    int ans = 1;
    long long acc = 1;
    while (acc != f) acc *= ++ans;
    cout << ans << endl;
  }
}
