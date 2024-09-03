#include <bits/stdc++.h>

#define MX 21
#define EPS 1e-10

using namespace std;
typedef vector<int> vi;

double P[MX];
vector<vi> AL;
int n, m;

int main() {
  cin >> n >> m;
  memset(P, 0, sizeof P);
  AL.assign(n, vi());
  P[0] = 1;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    AL[u].push_back(v);
    AL[v].push_back(u);
  }

  int j = 1;
  double ans = 0;
  while (true) {
    double Q[MX];
    memset(Q, 0, sizeof Q);
    for (int i = 0; i < n; ++i) {
      int size = AL[i].size();
      for (auto j : AL[i]) {
	Q[j] += P[i]/size;
      }
    }
    memcpy(P, Q, sizeof P);
    ans += j * P[n-1];
    P[n-1] = 0;
    double mx = *max_element(begin(P), end(P));
    if (mx < EPS) break;
    ++j;
  }

  printf("%.6lf\n", ans);
}
