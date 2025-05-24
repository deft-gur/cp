#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int n;
vvi g;
vi dp;
vi visited;

double dfs(int v) {
  if (visited[v]) return 0;
  visited[v] = 1;
  int child = 0;
  for (auto u : g[v]) {
    if (!visited[u]) ++child;
  }
  if (child == 0) return 0;
  double ret = 0;
  for (auto u : g[v]) {
    ret += dfs(u);
  }
  return (ret/child) + 1;
}

int main() {
  cin >> n;
  g.assign(n, vi(0));
  dp.assign(n, 0);
  visited.assign(n, 0);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cout << fixed << setprecision(7) << dfs(0) << endl;
}
