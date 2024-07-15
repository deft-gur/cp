#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;
  int a[n];

  for (int i = 0; i < n; ++i) cin >> a[i];
  
  int count = 1;
  set<int> products;
  for (int i = 0; i < n; ++i) {
    int len = products.size();
    set<int> newProd = products;
    for (auto v : products) {
      if (x % (v * a[i]) == 0) {
	newProd.insert(v*a[i]);
      }
    }
    products = newProd;

    if (products.find(x) != products.end()) {
      ++count;
      products.clear();
    }

    if (x % a[i] == 0) products.insert(a[i]);
  }

  cout << count << endl;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
