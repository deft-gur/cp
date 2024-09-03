// Think of this problem as maximum cardinality bipartite matching but directed version.
#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int n;
vector<vi> AL;
vi match;
vi visited;

int aug(int v) {
  if (visited[v]) return 0;

  visited[v] = 1;

  for (auto u : AL[v]) {
    if (match[u] == -1 || aug(match[u])) {
      match[u] = v; return 1;
    }
  }

  return 0;
}

int main() {
  cin >> n;
  AL.assign(1000, vi());
  match.assign(1000, -1);
  int x, y;

  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    --x; y += 499;
    AL[x].push_back(y); AL[y].push_back(x);
  }

  int mx = 0;
  for (int i = 0; i < 1000; ++i) {
    visited.assign(1000, 0);
    bool skip = false;
    for (auto u : AL[i]) {
      if (match[u] == -1) { match[u] = i; ++mx; skip = true; break; }
    }
    if (!skip && aug(i)) { ++mx; }
  }

  int tot = 0;
  for (int i = 0; i < 1000; ++i) {
    if (!AL[i].empty()) ++tot;
  }

  cout << (tot == mx ? "Slavko" : "Mirko") << '\n';
}
