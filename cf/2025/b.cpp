#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef vector<int> vi;
typedef vector<vi> vvi;
#define MOD (int)(1e9 + 7)
#define MX 1e5+1
vi n;
vi k;
//vvi memo;
vi memo;

int mult(int, int);
int bPow(int, int);

int dp(int n) {
  if (n == 0) return 1;
  if (memo[n]) return memo[n];
  int &res = memo[n];
  return res = bPow(2, n);
}

int bPow(int x, int a) {
  int res = 1;
  int y = x;
  while(a) {
    if (a % 2) res = mult(res, y);
    y = mult(y, y);
    a = a >> 1;
  }
  return res;
}

int modInv(int x) {
  return bPow(x, MOD-1);
}

int mult(int a, int b) {
  return (a * b) % MOD;
}

int add(int a, int b) {
  return (a + b) % MOD;
}

int32_t main() {
  int t;
  cin >> t;
  n.assign(t, 0);
  k.assign(t, 0);
  memo.assign(MX, 0);
  for (int i = 0; i < t; ++i) { cin >> n[i]; }
  for (int i = 0; i < t; ++i) { cin >> k[i]; }

  for (int i = 0; i < t; ++i) {
    cout << dp(k[i]) << '\n';
  }
}
