#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
int n;
vi a;
vii b;

int abs(int x) {
  return (x > 0) ? x : -x;
}

void solve() {
  cin >> n;
  a.assign(n, 0); b.assign(n, {0, 0});
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    b[i].first = abs(a[i]);
    b[i].second = i;
  }
  sort(b.begin(), b.end());
  bool ans = false;
  for (int i = 0; i <= ((n % 2 == 0) ? n/2 - 1 : n/2); ++i) {
    if (b[i].second == 0) {ans = true; break;}
  }
  if (n % 2 == 0 && b[n/2].second == 0) {
    ans = true;
  }
  cout << ((ans == true) ? "yes" : "no") << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
