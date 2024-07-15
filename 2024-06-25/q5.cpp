#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pli pair<ll, int>
#define tll tuple<ll, ll, ll>

const int MOD = 1000000007;

ll n;
int k;
map<pli, tll> memo;

tll conquer(ll n, int k) {
  if (k < 0) {
    return make_tuple(0ll, 0ll, 0ll);
  }
  if (n == 0) {
    return make_tuple(1ll, 1ll, 1ll);
  }
  if (memo.count({n, k})) {
    return memo[{n,k}];
  }

  int m = 63 - __builtin_clzll(n);
  ll num = (ll)1 << m;
  ll tmp1 = num - 1;
  ll tmp2 = n - num;
  ll sum1, l1, r1, sum2, r2, l2;
  tie(sum1, l1, r1) = conquer(tmp1, k);
  tie(sum2, l2, r2) = conquer(tmp2, k-1);
  ll sum = ((sum1 + sum2) + ((r1%MOD) * (l2%MOD))) % MOD;
  ll r = r2, l = l1;
  if (tmp2 == r2 - 1) {
    r = (r1 + r2);
  }
  if (tmp1 == (l1 - 1)) {
    l = (l2 + l1);
  }
  memo[{n, k}] = tuple<ll,ll,ll>{sum, l, r};
  return memo[{n, k}];
}

void solve() {
  cin >> n >> k;
  ll res, l, r;

  cout << get<0>(conquer(n-1,k)) << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
