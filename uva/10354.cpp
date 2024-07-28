// Complexity O(|V|^3) bounded by floydWarhsall call
#include <bits/stdc++.h>

using namespace std;

#define MX 105
#define INF 1000000000
int W[MX][MX];
// P[i][j]: i -> ... -> P[i][j] -> j
int P[MX][MX];
int AM[MX][MX];
int closed[MX];
int n, m, b, o, s, t;

void floydWarshall() {
  memcpy(AM, W, sizeof AM);
  //copy(&W[0][0], &W[0][0] + MX*MX, &AM[0][0]);
  memset(P, 0, sizeof P);
  for (int k = 1; k <= n; ++k) {
    if(closed[k]) continue;
    for (int i = 1; i <= n; ++i) {
      if(closed[i]) continue;
      for (int j = 1; j <= n; ++j) {
	if(closed[j]) continue;
	if (AM[i][k] + AM[k][j] < AM[i][j]) {
	  AM[i][j] = AM[i][k] + AM[k][j];
	  P[i][j] = P[k][j];
	}
      }
    }
  }
}

vector<int> getPath(int s, int t) {
  vector<int> res;
  int u = t;
  do {
    res.push_back(u);
    u = P[s][u];
  } while(u != s);

  if (s != t) res.push_back(s);
  reverse(res.begin(), res.end());
  return res;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  while (cin >> n >> m >> b >> o >> s >> t) {
    // Set W to be large costs.
    // (63)_2 (63)_2 (63)_2 (63)_2 > 1e9
    memset(W, 63, sizeof W);
    memset(closed, 0, sizeof closed);
    for (int i = 1; i <= n; ++i) {
      W[i][i] = 0;
    }
    for (int i = 1; i <= m; ++i) {
      int u, v, d;
      cin >> u >> v >> d;
      AM[u][v] = AM[v][u] = W[u][v] = W[v][u] = d;
      P[u][v] = u;
      P[v][u] = v;
    }
    floydWarshall();
    for (int i = 1; i <= n; ++i) {
      // NOTE: Using the getPath(b,o) will only work if there are one unique shortest path.
      // Thus we need to examine all possible shortest path.
      if (AM[b][o] == AM[b][i] + AM[i][o]) closed[i] = 1;
    }
    if (closed[s] || closed[t]) {
      cout << "MISSION IMPOSSIBLE." << endl;
      continue;
    }
    floydWarshall();
    if (AM[s][t] >= INF) cout << "MISSION IMPOSSIBLE." << endl;
    else cout << AM[s][t] << endl;
  }
}
