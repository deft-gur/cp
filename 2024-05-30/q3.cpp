#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  int s = n + m + 1;
  int a[s], b[s];
  for (int i = 0; i < s; ++i) cin >> a[i];
  for (int i = 0; i < s; ++i) cin >> b[i];

  int aa[s], bb[s], p[s];
  int as = 0, bs = 0;
  for (int i = 0; i < s; ++i) {
    aa[i] = bb[i] = p[i] = -1;

    if (as >= n) bb[i] = p[i] = b[i];
    if (bs >= m) aa[i] = p[i] = a[i];
    if (as - 1 >= n) aa[i] = b[i];
    if (bs - 1 >= m) bb[i] = a[i];

    int tmp = max(a[i], b[i]);
    if (aa[i] == -1) aa[i] = tmp;
    if (bb[i] == -1) bb[i] = tmp;
    if (p[i] == -1) p[i] = tmp;

    if (a[i] >= b[i]) ++as;
    else ++bs;
  }

  int sum = 0;
  for (int i = 0; i < s - 1; ++i)
    sum += p[i];
  int ans[s];
  ans[s-1] = sum;

  int sumA = 0;
  int sumB = 0;
  for (int i = s - 2; i >= 0; --i) {
    sum -= p[i];
    sumA += aa[i+1];
    sumB += bb[i+1];
    if (a[i] > b[i]) ans[i] = sum + sumA;
    else ans[i] = sum + sumB;
  }

  for (int i = 0; i < s; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
