#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef tuple<int, int, int> iii;
typedef vector<iii> viii;
int n, m;
vvii AL;
vi visited;
priority_queue<iii, viii, greater<iii>> pq;

void process(int u) {
  visited[u] = 1;
  for (auto &[v, w] : AL[u])
    if (!visited[v]) pq.emplace(w, v, u);
}

void solve() {
  AL.assign(n, vii());
  pq = priority_queue<iii, viii, greater<iii>>();
  visited.assign(n, 0);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    AL[u].emplace_back(v,w);
    AL[v].emplace_back(u,w);
  }

  process(0);
  int min = 0;
  int numEdges = 0;
  vii edges;
  while(!pq.empty()) {
    auto [w, v, u] = pq.top(); pq.pop();
    if (visited[v]) continue;
    min += w;
    process(v);
    if (u > v) swap(u, v);
    edges.emplace_back(u, v);
    if (++numEdges == n-1) break;
  }
  if (numEdges != n-1) {
    printf("Impossible\n");
  } else {
    sort(edges.begin(), edges.end());
    printf("%d\n", min);
    for (auto [u, v] : edges) {
      printf("%d %d\n", u, v);
    }
  }
}

int main() {
  while (true) {
    scanf("%d %d", &n, &m);
    if (n == 0 && m == 0) break;
    solve();
  }
}
