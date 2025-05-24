#include <bits/stdc++.h>

using namespace std;

#define MOD (ll)(1e9 + 7)
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, m, k, s;
vll factorial;
vii blocks;
// dp[i][j] represnting the number of path starting at block i to (n, m) while visiting j+1 number of drain batteries.
vvll dp;
vll val;
vvll memoPath;

ll modMult(ll x, ll y) {
  return (x * y) % MOD;
}

ll modPow(ll x, ll pow) {
  ll a = x;
  ll ans = 1;
  while(true) {
    if (pow == 0) return ans;
    if (pow & 1) ans = modMult(a, ans);
    a = modMult(a, a);
    pow = pow >> 1;
  }
}

ll modInv(ll x) {
  return modPow(x, MOD-2);
}

ll fact(int x) {
  if (x <= 1) return 1;
  if (factorial[x]) return factorial[x];
  ll ans = 1;
  ans = modMult(x, fact(x-1));
  return factorial[x] = ans;
}

ll nCr(int n, int r) {
  ll ans = 1;
  ll num = fact(n);
  ll den = modInv(modMult(fact(r), fact(n-r)));
  return modMult(num, den);
}

ll numOfPath(ii a, ii b) {
  int diffX = abs(a.first - b.first);
  int diffY = abs(a.second - b.second);
  return nCr(diffX + diffY, diffX);
}

ll numOfPath(int i, int j) {
  if (memoPath[i][j]) return memoPath[i][j];
  return memoPath[i][j] = numOfPath(blocks[i], blocks[j]);
}

ll modAdd(ll x, ll y) {
  return (((x + y) % MOD) + MOD) % MOD;
}

ll modSub(ll x, ll y) {
  return modAdd(x, -y);
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> k >> s;
  factorial.assign(3 * max(n, m), 0);
  factorial[0] = factorial[1] = 1;
  memoPath.assign(k+1, vll(k+1, 0));
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    blocks.emplace_back(x, y);
  }
  ii endPoint(n, m);
  blocks.emplace_back(1, 1);
  sort(blocks.begin(), blocks.end());

  dp.assign(k+1, vll(21, 0));
  // dp[i][0] = numOfPath from i to end - sum from j = i+1 to k numofPath from i to j * dp[j][0]
  vll tmp; 
  for (int i = k; i >= 0; --i) {
    tmp.assign(21, 0);
    tmp[0] = numOfPath(blocks[i], endPoint);
    for (int v = 0; v < 21; ++v) {
      if (tmp[v] == 0) tmp[v] = modSub(tmp[v-1], dp[i][v-1]);
      dp[i][v] = tmp[v];
      //dp[i][v] = numOfPath(blocks[i], endPoint);
      if (v != 20) {
	for (int j = i+1; j <= k; ++j) { 
	  if (blocks[j].first >= blocks[i].first && blocks[j].second >= blocks[i].second)
	    dp[i][v] = modSub(dp[i][v], modMult(dp[j][v], numOfPath(i, j))); 
	} 
      }
      //for (int j = 0; j <= v-1; ++j) { dp[i][v] = modSub(dp[i][v], dp[i][j]); }
    }
  }

  val.assign(21, 0);
  val[0] = s;
  for (int i = 1; i < 21; ++i) {
    val[i] = ceil((double)val[i-1]/2);
  }

  ll ans = 0;
  for (int v = 0; v < 21; ++v) {
    //cout << val[v] << ", "<< v << ": " << dp[0][v] << endl;
    ans = modAdd(ans, modMult(val[v], dp[0][v]));
  }
  //cout << ans << '\n';
  //cout << numOfPath(make_pair(1, 1), endPoint) << '\n';
  ans = modMult(ans, modInv(numOfPath(make_pair(1, 1), endPoint)));
  cout << ans << '\n';
}
