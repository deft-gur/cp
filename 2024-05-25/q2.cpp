#include <iostream>

using namespace std;

void solve() {
  int n;
  cin >>n;
  int c;
  int a[n];
  for (int i = 0; i < n; ++i) cin >> a[i];
  int s = a[0];
  for (int i = 1; i < n; ++i) {
    s = min(s, a[i]);
  }
  int s2 = a[0];
  for (int i = 0; i < n; ++i) {
    if (a[i] % s2 != 0 && a[i] % s != 0) s2 = a[i];
  }
  int ans = true;
  /* cout << "s:" << s << s2 << endl; */
  for (int i = 0; i < n; ++i) {
    if (a[i] % s != 0 && a[i] % s2 != 0) {
      ans = false;
      break;
    }
  }

  cout << (ans ? "YES" : "NO") << endl;
}

int main() {
  int t;
  cin >> t;
  while( t-- ) solve();
}
