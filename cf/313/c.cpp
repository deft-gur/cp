#include <bits/stdc++.h>

using namespace std;

#define MOD (ll)(1e9 + 7)
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
vll dp;
vii blocks;
vll factorials;
int h, w, n;

ll modMult(ll x, ll y) {
  return (x * y) % MOD;
}

ll modPow(ll x, ll pow) {
  ll ans = 1;
  ll a = x;
  while (true) {
    if (pow == 0) return ans;
    if (pow & 1) { ans = modMult(ans, a); }
    a = modMult(a, a);
    pow = pow >> 1;
  }
}

ll modInv(ll x) {
  return modPow(x, MOD-2);
}

ll fact(ll x) {
  if (x <= 1) return 1;
  if (factorials[x]) return factorials[x];
  ll ans = 1;
  ans = modMult(x, fact(x-1));
  factorials[x] = ans;
  return ans;
}

ll numberOfPaths(ii a, ii b) {
  ll diffX = abs(a.first - b.first), diffY = abs(a.second - b.second);
  ll num = fact(diffX + diffY);
  ll den = modInv(modMult(fact(diffX), fact(diffY)));
  return modMult(num, den);
}

ll modAdd(ll x, ll y) {
  return (((x + y) % MOD) + MOD) % MOD;
}

ll modSub(ll x, ll y) {
  return modAdd(x, (-y) % MOD);
}

int main() {
  cin >> h >> w >> n;
  factorials.assign(4*max(h, w), 0);
  for (int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y;
    blocks.emplace_back(x, y);
  }
  blocks.emplace_back(h, w);
  sort(blocks.begin(), blocks.end());

  dp.assign(n+1, 0);
  for (int i = 0; i <= n; ++i) {
    dp[i] = numberOfPaths(ii(1, 1), blocks[i]);
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (blocks[i].first >= blocks[j].first && blocks[i].second >= blocks[j].second)
	dp[i] = modSub(dp[i], modMult(dp[j], numberOfPaths(blocks[j], blocks[i])));
    }
  }
  cout << dp[n] << '\n';
}
