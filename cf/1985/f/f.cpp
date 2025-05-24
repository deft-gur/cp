#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
typedef vector<ll> vll;
ll n, h;
vll att, cd;

ll dmgDealt(ll t) {
  ll dmg = 0;
  for (int i = 0; i < n; ++i) {
    dmg += att[i] * (1 + ((t-1)/cd[i]));
  }
  return dmg;
}

ll findTurn(ll l, ll r) {
  if (l == r) return l;

  ll m = (l+r)/2;
  ll dmg = dmgDealt(m);
  if (dmgDealt(m) >= h) {
    return findTurn(l, m);
  } else {
    return findTurn(m+1, r);
  }
}

void solve() {
  cin >> h >> n;
  att.assign(n, 0);
  cd.assign(n, 0);
  for (int i = 0; i < n; ++i)  cin >> att[i];
  for (int i = 0; i < n; ++i)  cin >> cd[i];
  ll mxCd = *max_element(cd.begin(), cd.end());
  cout << findTurn(1, h*mxCd) << endl;
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}
