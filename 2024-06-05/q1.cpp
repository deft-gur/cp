#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    int a[7];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; ++i) {
      char c;
      cin >> c;
      ++a[c - 'A'];
    }
    int need = 0;
    for (int i = 0; i < 7; ++i) {
      need += min(0, a[i] - m);
    }
    cout << -1 * need << endl;
  }
}
