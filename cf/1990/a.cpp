#include <bits/stdc++.h>

using namespace std;
int a[51];
int n;

void solve() {
  cin >> n;
  memset(a, 0, sizeof a);
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    ++a[tmp];
  }
  bool ans = false;
  for (int i = 1; i < 51; ++i) {
    if (a[i] % 2) ans = true;
  }
  cout << (ans ? "YES" : "NO") << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
