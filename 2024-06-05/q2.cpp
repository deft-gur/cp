#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, f, k;
  cin >>n >>f >> k;
  int a[n+2];
  a[0] = 0;
  a[n+1] = 0;
  int val;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (i == f) val = a[i];
  }
  /* cout << "val:" << val<< endl; */
  sort(a+1, a+n+1);
  reverse(a+1, a+n+1);
  /* for (int i = 1; i <= n; ++i) { */
  /*   cout << a[i]; */
  /* } */

  /* cout << "a[k]:" << a[k] << "," << k << endl; */
  if (n != 1 && a[k] == val && a[k+1] == val) cout << "maybe";
  else if(a[k] <= val) cout << "yes";
  else cout << "no";
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
