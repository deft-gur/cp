#include <bits/stdc++.h>

using namespace std;
#define vi vector<int>

int len, c;
int p[55];
int dp[55][55];


int solve(int l, int r) {
  int &res = dp[l][r];
  if (res != -1) return res;
  if (l+1 == r) return res = 0;
  res = 1e9;

  for (int i = 1; l + i < r; ++i) {
    res = min(p[r] - p[l] + solve(l, l + i) + solve(l + i, r), res);
  }
  return res;
}

int main() {
  while(true) {
    scanf("%d", &len);
    if (len == 0) break;
    scanf("%d", &c);
    memset(dp, -1, sizeof(dp));
    p[0] = 0;
    for (int i = 1; i <= c; ++i) {
      scanf("%d", &p[i]);
    }
    p[c+1] = len;
    c += 2;
    sort(p, p + c);

    printf("The minimum cutting is %d.\n", solve(0, c-1));
  }
}
