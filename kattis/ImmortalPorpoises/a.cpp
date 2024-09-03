#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int MOD = 1e9;
const int n = 2;

vvi Mult(vvi &A, vvi &B) {
  vvi res;
  res.assign(n, vi(n, 0));
  for (int i = 0; i < n; ++i) 
    for (int k = 0; k < n; ++k) 
      for (int j = 0; j < n; ++j) { res[i][j] += (A[i][k] * B[k][j]) % MOD; res[i][j] = res[i][j] % MOD;}

  return res;
}

vvi pow(vvi &A, int l) {
  vvi res;
  res.assign(n, vi(n, 0));
  for (int i = 0; i < n; ++i) { res[i][i] = 1; }
  vvi B(A);

  while (l) {
    if (l % 2) res = Mult(res, B);
    B = Mult(B, B);
    l = l >> 1;
  }
  return res;
}


/*
[1 1]^i[1]   [ fib(i+1) ]
[1 0]  [1] = [ fib(i)   ]
________
[1 1]^i   = [ fib(i+1)   fib(i) ]
[1 0]       [ fib(i)   fib(i-1) ]
*/
int32_t main() {
  int t;
  int x, y;
  vvi a;
  a.assign(n, vi(n, 1)); a[1][1] = 0;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cin >> x >> y;
    vvi res = pow(a, y-1);
    cout << x << ' ' << res[0][0] << '\n';
  }
}
