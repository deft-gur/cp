#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int MAXK = 1e5+7;
const int MOD = 998244353;
int k, n;
vvi dp, divisor, visited;
vi primes;

int mul(int x, int y) {
  return ((x * y) % MOD + MOD) % MOD;
}

int add(int x, int y) {
  return ((x + y) % MOD + MOD) % MOD;
}

int pow(int a, int b) {
  int ans = 1;
  int tmp = a;
  while(b) {
    if (b % 2) ans = mul(ans, tmp);
    tmp = mul(tmp, tmp);
    b = b >> 1;
  }
  return ans;
}

int inv(int y) {
  return pow(y, MOD-2);
}

int divide(int x, int y) {
  return mul(x, inv(y));
}

int binom(int n, int j) {
  if (j == 0) return 1;
  if (j > n/2) return binom(n, n-j);
  if (j > n) return 0;
  int ans = 1;
  for (int i = 0; i < j; ++i) {
    ans = mul(ans, n-i);
    ans = divide(ans, i+1);
  }
  return ans;
}

int getDp(int k, int j) {
  if (k == 1) return 0;
  if (j == 1) return 1;
  if (visited[k][j]) return dp[k][j];
  visited[k][j] = 1;
  for (auto p : divisor[k]) {
    dp[k][j] = add(dp[k][j], getDp(k/p, j-1));
  }
  return dp[k][j];
}

void solve() {
  cin >> k >> n;

  for (int i = 1; i <= k; ++i) {
    int ans = 0;
    for (int j = 1; j <= 16; ++j) {
      if (i == 1) ans = n;
      else ans = add(ans, mul(binom(n+1, j+1), getDp(i, j)));
    }
    cout << ans << ' ';
  }
  cout << '\n';
}

int32_t main() {
  divisor.assign(MAXK, vi(0));
  primes.assign(MAXK, 1);
  for (int i = 2; i < MAXK; ++i) {
    if (!primes[i]) continue;
    for (int j = i; j < MAXK; j+=i) {
      if (i == j) continue;
      primes[j] = 0;
      divisor[j].push_back(i);
    }
  }
  visited.assign(MAXK, vi(n+1, 0));
  dp.assign(MAXK, vi(17, 0));

  int t; cin >> t;
  while(t--) solve();
}
