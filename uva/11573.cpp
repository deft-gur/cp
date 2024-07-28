#include <bits/stdc++.h>

using namespace std;

#define MX 1005
int M[MX][MX];
int C[MX*MX][MX*MX];
int n, m;

# incomplete
int dr[]={-1, -

void floydWarshall() {
  memset(C, 63, sizeof C);
  for (int i = 1; i <= n * m; ++i) {
    for (int j = 1; j <= n * m; ++j) {
      C[i*n + j*m][(i-1)*n - k
    }
    C[i*n + j*m][i*n+j*m] = 0;
  }
  for (int k = 1; k <= n * m; ++k) {
    for (int i = 1; i <= n * m; ++i) {
      for (int j = 1; j <= n * m; ++j) {
	C[i][j] = min(C[i][j], C[i][k] + C[k][j]);
      }
    }
  }
}

int main() {
  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> M[i][j];
    }
  }

  floydWarshall();
  int t;
  cin >> t;
  while(t--) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << C[r1*n + c1*m][r2*n + c2*m];
  }
}
