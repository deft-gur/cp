#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ii pair<int, int>
#define vvi vector< vector<ii>>

#define loop(x, n) for (int x = 1; x <= n; ++x)

struct digraph {
  vvi neigh;
  int capacity;
  int size;

  digraph(int n) : neigh(n+1), size(n), capacity(n+1) {}
  void add(int x, int y, int w = 1) {
    neigh[x].push_back(make_pair(y, w));
  }
};

void dijkstra(digraph &d, int s) {
  vi dist(d.capacity, 1e9);
  vi par(d.capacity, -1);
  dist[s] = 0;
  priority_queue<ii> q;
  q.push(make_pair(0, s));
  int visited[d.capacity];
  memset(visited, 0, sizeof(visited));
  while(!q.empty()) {
    ii t = q.top();
    q.pop();
    int u = t.second;
    if (visited[u]) continue;
    visited[u] = 1;
    for (int i = 0; i < d.neigh[u].size(); ++i) {
      int v = d.neigh[u][i].first;
      int w = d.neigh[u][i].second;
      if (dist[u] + w < dist[v]) {
	dist[v] = dist[u] + w;
	par[v] = u;
	q.push(make_pair(-dist[v], v));
      }
    }
  }

  loop(i, d.size) {
    printf("shortest distance from %d to %d: %d\n", s, i, dist[i]);
    vi path;
    path.push_back(i);
    int suc = i;
    while(suc != s) {
      suc = par[suc];
      path.push_back(suc);
    }
    for (int i = path.size() - 1; i >= 0; --i) {
      if (i != path.size() - 1) printf(", ");
      printf("%d", path[i]);
    }
    printf("\n");
  }
}

int main() {
  int n, s;
  scanf("%d", &n);
  digraph d{n};
  scanf("%d", &n);
  scanf("%d", &s);
  for (int i = 0; i < n; ++i) {
    int x, y, w;
    scanf("%d %d %d", &x, &y, &w);
    d.add(x, y, w);
  }

  dijkstra(d, s);
}
