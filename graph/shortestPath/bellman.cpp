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

void bellman(digraph &d, int s) {
  vi dist(d.capacity, 1e9);
  dist[s] = 0;
  vi p(d.capacity, -1);
  loop(j, d.size)
    loop(i, d.size)
      for (auto &e : d.neigh[i]) {
	int x = e.first;
	int w = e.second;
	int tmp = dist[i] + w;
	if (dist[x] > tmp) dist[x] = tmp, p[x] = i;
      }

  loop(i, d.size){
    printf("shorest length for %d to %d is: %d\n", s, i, dist[i]);
    vi path;
    int suc = i;
    path.push_back(i);
    while(suc != s) {
      path.push_back(p[suc]);
      suc = p[suc];
    }
    for (int i = path.size() - 1; i >= 0; --i) {
      if (i != path.size()- 1) printf(", ");
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

  bellman(d, s);
}
