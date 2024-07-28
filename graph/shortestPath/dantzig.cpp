#include <bits/stdc++.h>

using namespace std;

#define MX 10000
typedef pair<int, int> ii;
typedef vector<ii> vii;

int y[MX];
int p[MX];
int visited[MX];
int n, m, s;
vii AL[MX];
int AM[MX][MX];

void dfs(int u, int parent, int cost) {
  if (visited[u]) return;
  visited[u] = 1;
  p[u] = parent;
  if (parent) y[u] += cost + y[parent];
  for (auto [v, w] : AL[u]) {
    dfs(v, u, w);
  }
}

// Return true iff node v is in the path from s to u in p.
bool inPath(int u, int v) {
  int node = u;
  while(node) {
    if (node == v) return true;
    node = p[node];
  }
  return false;
}

string getPath(int u) {
  int node = u;
  string path = "";
  while(node) { path += " ," + to_string(node); node = p[node]; }
  reverse(path.begin(), path.end());
  return path;
}

void dantzig() {
  bool restart = false;
  for (int u = 1; u <= n; ++u) {
    for (auto [v, w] : AL[u]) {
      if (y[v] > y[u] + w) {
        if (inPath(u, v)) {
          cout << "Negative cycle found: ";
          string path = getPath(u);
          path += ", " + to_string(v);
          cout << path << endl;
          return;
        } else {
          restart = true;
          y[v] = y[u] + w;
          p[v] = u;
        }
      }
    }
    if (restart) restart = false, u = 0;
  }
}

int main() {
  cin >> n >> m >> s;
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    AL[u].emplace_back(v, w);
    AM[u][v] = w;
  }
  dfs(s, 0, 0);
  dantzig();
  for (int i = 1; i <= n; ++i) {
    cout << "Min cost for " << i << " is: " << y[i] << " path is: " << getPath(i) << endl;
  }
  return 0;
}
