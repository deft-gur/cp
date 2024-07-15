#include <bits/stdc++.h>

using namespace std;
#define MX 105
const int MOD = 1000000;

int dp[MX][MX];

int solve(int n, int k) {
  int &res = dp[n][k];

  if (res != -1) return res;
  res = 0;
  if (k == 1) return res = 1;

  for (int i = 0; i <= n; ++i) {
    res += solve(n-i, k-1);
    res %= MOD;
  }

  return res;
}

int main() {
  int n, k;
  memset(dp, -1, sizeof(dp));
  while (true) {
    scanf("%d %d", &n, &k);
    if (n == 0 && k == 0) break;
    printf("%d\n", solve(n, k));
  }
}
