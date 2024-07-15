#include <bits/stdc++.h>

using namespace std;


int inversions(int x[], int l, int r) {
  if (l == r) return 0;

  int mid = (l + r)/2;
  int leftInv = inversions(x, l, mid);
  int rightInv = inversions(x, mid+1, r);

  int rest = 0;
  int p, q;
  p = l;
  q = mid+1;
  int ans[r - l + 1];
  int cur = 0;
  while(p <= mid && q <= r) {
    if (x[p] < x[q]) {
      rest += q - mid - 1;
      ans[cur] = x[p];
      ++p;
    } else {
      ans[cur] = x[q];
      ++q;
    }
    ++cur;
  }

  while (p <= mid) {
    rest += q - mid - 1;
    ans[cur] = x[p];
    ++cur;
    ++p;
  }

  while (q <= r) {
    ans[cur] = x[q];
    ++cur;
    ++q;
  }
  for (int i=l; i <= r; ++i) {
    x[i] = ans[i-l];
  }

  return (rest + leftInv + rightInv) % 2;
}

void solve() {
  int n;
  cin >> n;
  int a[n], b[n], x[n], y[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  copy(a, a+n, x);
  copy(b, b+n, y);
  sort(x, x+n);
  sort(y, y+n);
  bool same = true;
  for (int i = 0; i < n; ++i) {
    same &= (x[i] == y[i]);
  }
  cout << (((inversions(a, 0, n-1) % 2) == (inversions(b, 0, n-1) % 2)) && same ? "YES" : "NO") << endl;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}	
