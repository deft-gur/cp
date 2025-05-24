#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int n, t;
vi a, b, c;

int main() {
  cin >> n >> t;
  a.assign(n, 0); b.assign(n, 0); c.assign(n, 0);
  for (int i = 0; i < n; ++i) { cin >> a[i]; }
  for (int i = 0; i < n; ++i) { cin >> b[i]; }

  int workDone = 0;
  for (int i = n-1; i >= 0; --i) {
    c[i] = a[i]/b[i];
    workDone += c[i];
    if (workDone >= t) {
      c[i] -= (workDone - t);
      break;
    }
  }
  for (int i = 0; i < n; ++i) cout << (workDone >= t ? c[i] : 0) << " ";
  cout << '\n';

  return 0;
}
