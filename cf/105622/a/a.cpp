#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> ii;

vii tree;
vi visited;
int n;

int findCycle(int s, int lvl) {
  if (visited[s]) return 0;
  visited[s] = 1;
  //printf("called on %d, level %d\n", s, lvl);
  if (lvl == 2) return s;
  for (auto v : tree[s]) {
    //printf("calling %d, %d\n", s, v);
    int res = findCycle(v, lvl+1);
    if (res) return res;
  }
  return 0;
}



int main() {
  cin >> n;
  tree.assign(n+1, vi(0));
  for (int i = 0; i < n; ++i) {
    int u, v; cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  int u, v;
  for (u = 1; u <= n; ++u) {
    visited.assign(n+1, 0);
    //printf("calling findCycle\n");
    v = findCycle(u, 0);
    if (v) break;
  }
  printf("%d %d\n", u, v);

  return 0;
}
