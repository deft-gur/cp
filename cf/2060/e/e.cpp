#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
vvi f, g;
vi cG, cF;
vi visited;
int m1, m2, n, op;

void dfs(vvi &g, vi &cG, int v, int c) {
  if (visited[v]) return;
  cG[v] = c;
  visited[v] = 1;
  for (auto u : g[v]) {
    dfs(g, cG, u, c);
  }
}

void delDFS(int v, int c) {
  if (visited[v]) return;
  cF[v] = c;
  visited[v] = 1;
  for (auto u : f[v]) {
    if (cG[u] != cG[v]) {
      ++op;
      continue;
    }
    delDFS(u, c);
  }
}

int assignComp(vvi &h, vi &cH, bool del = false) {
  visited.assign(n, 0);
  cH.assign(n, 0);
  int c = 0;
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      if (del == false) dfs(h, cH, i, ++c);
      else delDFS(i, ++c);
    }
  }
  return c;
}


void solve() {
  cin >> n >> m1 >> m2;
  op = 0;
  int u, v;
  f.assign(n, vi(0,0));
  g.assign(n, vi(0,0));
  for (int i = 0; i < m1; ++i) {
    cin >> u >> v;
    --u, --v;
    f[u].push_back(v); f[v].push_back(u);
  }
  for (int i = 0; i < m2; ++i) {
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v); g[v].push_back(u);
  }

  int c1 = assignComp(g, cG, false);
  int c2 = assignComp(f, cF, true);
  //printf("%d %d %d\n", op, c1, c2);
  int ans = op/2 + c2 - c1;
  cout << ans << endl;
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}
