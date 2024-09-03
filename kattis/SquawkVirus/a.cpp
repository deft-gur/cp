#include <bits/stdc++.h>

#define int long long

using namespace std;
typedef vector<int> vi;

int n, m, s, t;
vector<vi> AL;

vector<vi> Mult(vector<vi> &A, vector<vi> &B) {
  vector<vi> res;
  res.assign(n, vi(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int k = 0; k < n; ++k) {
      for (int j = 0; j < n; ++j) {
	res[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return res;
}

vector<vi> pow(vector<vi> &A, int l) {
  vector<vi> res;
  res.assign(n, vi(n, 0));
  for (int i = 0; i < n; ++i) { res[i][i] = 1; }
  vector<vi> B(A);

  while(l) {
    if (l % 2) res = Mult(res, B);
    B = Mult(B, B);
    l = l >> 1;
  }

  return res;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> s >> t;
  AL.assign(n, vi(n, 0));
  int u, v;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    AL[u][v] = AL[v][u] = 1;
  }
  vector<vi> a = pow(AL, t);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += a[i][s];
  }
  cout << ans << '\n';

  return 0;
}
