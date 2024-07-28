#include <bits/stdc++.h>

using namespace std;
#define MX 105
int a[105];
int n;

void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  int m = 0;
  for (int i = 0; 2*i < n; ++i) {
    m = max(a[2*i], m);
  }
  cout << m << endl;
}


int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
