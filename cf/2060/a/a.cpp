#include <bits/stdc++.h>

using namespace std;

int a[6];

int checkAns() {
  int tmp = 0;
  for (int i = 1; i <= 3; ++i) {
    if (a[i+2] == a[i] + a[i+1]) ++tmp;
  }
  return tmp;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    cin >> a[1] >> a[2] >> a[4] >> a[5];
    int ans = 0;
    a[3] = a[5] - a[4];
    ans = max(ans, checkAns());
    a[3] = a[1] + a[2];
    ans = max(ans, checkAns());
    a[3] = a[4] - a[2];
    ans = max(ans, checkAns());
    cout << ans << '\n';
  }
}
