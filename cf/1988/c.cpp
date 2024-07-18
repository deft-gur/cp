#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  ll n;
  cin >> n;
  vector<ll> a;
  a.emplace_back(n);

  ll nn = n;
  while (n) {
    ll bit = n & -n;
    if (nn ^ bit) 
      a.emplace_back(nn ^ bit);
    n -= bit;
  }
  cout << a.size() << endl;
  sort(a.begin(), a.end());
  for (auto v : a) {
    cout << v << " ";
  }
  cout << endl;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}
