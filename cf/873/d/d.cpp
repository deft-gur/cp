#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
int n, k;
vi a;

int solve(int l, int r, int c) {
  if (l == r-1) { return 1; }
  if (c == 1) {
    return 1;
  }

  int m = (l+r)/2;
  swap(a[m-1], a[m]);
  int x = solve(l, m, c-2);
  int y = solve(m, r, c-1-x);
  return x + y + 1;
}

int main() {
  cin >> n >> k;
  a.assign(n, 0);
  for (int i = 0; i < n; ++i) a[i] = i;
  int ans = solve(0, n, k);
  if (k == ans) {
    for (int i = 0; i < n; ++i) {
      cout << a[i]+1 << " ";
    }
    cout << endl;
  } else {
    cout << -1 << endl;
  }
}
