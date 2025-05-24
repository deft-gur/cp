#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
int n;
vi a, odd, even;

void solve() {
  cin >> n;
  a.assign(n, 0);
  odd.assign(n/2, 0);
  even.assign(n/2 + (n%2), 0);
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i]--;
    if (i % 2 == 0) {
      even[i/2] = a[i];
    } else {
      odd[i/2] = a[i];
    }
  }

  sort(even.begin(), even.end());
  sort(odd.begin(), odd.end());
  vi b(n);
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) b[i] = even[i/2];
    else b[i] = odd[i/2];
  }

  auto sign = [&] (vector<int> v) -> int {
    int ret = 0;
    for (int i = 0; i < n; ++i) {
      while(v[i] != i) {
	swap(v[i], v[v[i]]);
	ret ^= 1;
      }
    }
    return ret;
  };
  if (sign(a) != sign(b)) {
    swap(b[n-1], b[n-3]);
  }
  for (int i = 0; i < n; ++i) {
    cout << b[i] + 1 << " \n"[i+1==n];
  }
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
