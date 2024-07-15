#include <bits/stdc++.h>

using namespace std;


double dp[2002][2002];

int main() {
  int n, m;
  double p;
  scanf("%d %d %lf", &n, &m, &p);
  for (int i = 0; i <= m; ++i) {
    dp[0][i] = 1;
    for (int j = 1; j <= m; ++j) {
      dp[j][i] = dp[j-1][i];
      if (j-1 == i) {
        dp[j][i] = 1 - pow(p, i+1);
      } else if (j - 1 > i) {
        // If we imagine that we have a size j-1 column and the sequence of
        // goods are <= i. Now we need to consider a size j column in order to
        // go over > i. We need a length i+1 sequence of goods at the end.
        // ???0111.111 (length i).
        dp[j][i] -= pow(p, i+1) * (1-p) * dp[j-(i+2)][i];
      }
    }
  }
  double res = 0;
  for (int i = 1; i <= m; ++i) {
    res += i * (pow(dp[m][i], n) - pow(dp[m][i-1], n));
  }
  printf("%lf \n", res);
}
