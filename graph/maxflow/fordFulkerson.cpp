#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, m, s, t;

vvi AL;
vvi ALRes;
vi visited;
vi parent;
int flow;
vvi x;

void dfs() {
  stack<int> st;
  st.push(s);
  while(!st.empty()) {
   int u = st.top(); st.pop();
    visited[u] = 1;
    if (u == t) break;
    for (int v = 0; v < n; ++v) {
      if (ALRes[u][v] <= 0) continue;
      if (visited[v]) continue;
      st.push(v);
      parent[v] = u;
    }
  }
}

void fordFulkerson() {
  flow = 0;
  x.assign(n, vi(n, 0));
  while (true) {
    visited.assign(n, 0);
    parent.assign(n, 0);
    // Find an st path in the residual digraph.
    dfs();
    // Check if such st path exists.
    if (!visited[t]) break;

    vii stDipath;
    int u = t;
    while (u != s) {
      stDipath.emplace_back(parent[u], u);
      u = parent[u];
    }
    reverse(stDipath.begin(), stDipath.end());

    int pathFlow = INT_MAX;
    for (auto [u, v] : stDipath) {
      pathFlow = min(pathFlow, ALRes[u][v]);
    }

    printf("st path find!\n");
    // Update residual graph and the x values.
    for (auto [u, v] : stDipath) {
      printf("%d-%d, ", u, v);
      ALRes[u][v] -= pathFlow;
      ALRes[v][u] += pathFlow;
      if (AL[u][v] > 0){
	int tmp = AL[u][v] - x[u][v];
	x[u][v] += min(pathFlow, tmp);
	if (pathFlow > tmp) {
	  x[v][u] -= (pathFlow - tmp);
	}
      } else {
	int tmp = x[v][u];
	x[v][u] -= min(pathFlow, tmp);
	if (pathFlow > tmp) {
	  x[u][v] += (pathFlow - tmp);
	}
      }
    }
    printf("\n");

    flow += pathFlow;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%d, ", x[i][j]);
    }
    printf("\n");
  }
  printf("max flow: %d\n", flow);

  // Find the nodes reacahble from s. This set is our st cut.
  for (int i = 0; i < n; ++i) {
    if (visited[i]) printf("%d, ", i);
  }
  printf("\n");
}

int main() {
  scanf("%d %d", &n, &m);
  scanf("%d %d", &s, &t);

  AL.assign(n, vi(n, 0));
  ALRes.assign(n, vi(n, 0));

  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    AL[u][v] = w;
    ALRes[u][v] = w;
  }
  fordFulkerson();
}
