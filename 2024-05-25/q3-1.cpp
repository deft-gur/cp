#include <bits/stdc++.h>

using namespace std;

int middle(int a, int b, int c) {
  int s[] = {a, b, c};
  sort(s, s+3);
  return s[1];
}

void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) { cin >> a[i]; }

  int m = min(a[0], a[1]);
  for (int i = 0; i < n - 2; ++i) {
    m = max(m, middle(a[i], a[i+1], a[i+2]));
  }
  cout << m << endl;
}

int main() {
  int t;
  cin >> t;
  while( t-- ) solve();
}
