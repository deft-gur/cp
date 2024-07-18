#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  bool flag = false;
  string a;
  int ones = 0;
  int zeros = 0;
  cin >> a;
  for (int i = 0; i < n; ++i) {
    if (a[i] == '1') {
      ++ones;
      if (flag) {
	++zeros;
	flag = false;
      }
    }
    else {
      flag = true;
    }
  }
  if (flag) ++zeros;

  //cout << "n " << n << endl;
  //cout << "ones" << ones << " zeros" << zeros << endl;
  if (ones > zeros) cout << "YES";
  else cout << "NO";
  cout << endl;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}
