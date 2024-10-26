#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll mod(ll a, ll n) {
  return (a % n) ? a % n : n;
}
void solve() {
  int n, q;
  cin >> n >> q;
  vector<ll> a(n), p(1);
  for (ll &r : a) {
    cin >> r;
    p.push_back(p.back() + r);
  }
  for (ll &r : a) p.push_back(p.back() + r);

  while(q--) {
    ll l, r;
    cin >> l >> r;
    --l; --r;
    ll i = l/n, j = r/n;
    ll d = (j - i + 1);
    l %= n; r %= n;
    cout << p[n] * d - (p[l+i] - p[i]) - (p[n+j]-p[j+r+1]) << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
