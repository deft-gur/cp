#include <bits/stdc++.h>
#include "../../ds/unionFind.cpp"

typedef vector<tuple<int, int, int>> viii;

void kruskal() {
  int n, m;
  scanf("%d %d", &n, &m);
  viii EL(m);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    EL[i] = {w, u, v};
  }
  sort(EL.begin(), EL.end());

  UnionFind UF(n);
  int w, u, v;
  int edges = 0;
  viii MSTEdges;
  int cost = 0;
  for (auto &e : EL) {
    tie(w, u, v) = e;
    if (UF.isSameSet(u, v)) continue;
    MSTEdges.emplace_back(w,u,v);
    cost += w;
    UF.unionSet(u, v);
    ++edges;
    if (edges == n-1) break;
  }
}

int main() {
  kruskal();
}
