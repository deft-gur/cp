#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
vi a;

int main() {
  int t; cin >> t;
  while(t--) {
    int n;
    cin >> n;
    a.assign(n, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 1;
    for (int i = 0; i < n; ++i) {
      if (a[i] <= max(2*i, 2*(n-1-i))) { ans = 0; break; }
    }
    cout << (ans ? "YES" : "NO") << endl;
  }
}
