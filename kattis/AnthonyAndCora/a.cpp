#include <bits/stdc++.h>

#define MX 1005

using namespace std;
double A[2*MX][MX];

int main() {
  int N, M;
  cin >> N >> M;
  memset(A, 0, sizeof A);
  A[N + M - 1][N] = 1;
  double p;
  for (int i = N+M-2; i >= 0; --i) {
    cin >> p;
    for (int j = 0; j <= N; ++j) {
      A[i][j] += A[i+1][j] * p;
      A[i][j] += A[i+1][j+1] * (1 - p);
    }
  }
  double ans = 0;
  for (int j = 1; j <= N; ++j) {
    ans += A[0][j];
  }
  printf("%.6f\n", ans);
}
