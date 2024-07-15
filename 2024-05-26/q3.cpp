#include <bits/stdc++.h>

using namespace std;

#define ll long long

int a[2000];
int contains[2000];
int n = 0;
set<int> s;
ll least = 1;

void l() {
  least = 1;
  for (int i = 0; i < n; ++i) {
    if (contains[i] != 0)
      least = least * a[i] / __gcd((int)least, a[i]);
  }
}

int findSol(int size, int q) {
  l();
  if (s.count(least)) {
    int ans = 0;
    for (int i = q; i >= 0; --i) {
      contains[i] = 0;
      ans = max(findSol(size-1, i-1), ans);
      contains[i] = -1;
    }
    return ans;
  }

  return size;
}

void solve() {
  least = 1;
  cin >> n;
  s.clear();
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    s.insert(a[i]);
  }
  sort(a, a+n);
  memset(contains, -1, n * sizeof(int));

  for (int i = 0; i < n; ++i) {
    least = least * a[i] / __gcd((int)least, a[i]);
  }
  cout << findSol(n, n-1) << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
