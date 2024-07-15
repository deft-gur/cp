// Find the lowest common ancestor in a tree.
// See https://cp-algorithms.com/graph/lca.html
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vii> vvii;

//#define L(i) 2*i + 1
//#define R(i) 2*i + 2
#define L(i) (i << 1) | 1
#define R(i) (i << 1) + 2


struct LCA {
  vi euler, height, first, visited;
  vi T;
  int numNodes;
  int eulerSize;
  vvii AL;


  void DFS(int u, int h) {
    visited[u] = 1;
    height[u] = h;
    first[u] = euler.size();
    euler.push_back(u);
    for (auto [v, w] : AL[u]) {
      if (!visited[v]) {
	DFS(v, h+1);
	euler.push_back(u);
      }
    }
  }

  // Build segment tree on height.
  void build(int v, int tl, int tr) {
    if (tl == tr) {
      T[v] = euler[tl];
      return;
    }
    int tm = (tl + tr)/2;
    build(L(v), tl, tm);
    build(R(v), tm+1, tr);
    T[v] = height[T[L(v)]] < height[T[R(v)]] ? T[L(v)] : T[R(v)];
  }

  // Query the samllest height.
  int query(int v, int tl, int tr, int l, int r) {
    assert(v >= 0);
    if (l > r) return -1;
    if (tl == l && tr == r) return T[v];

    int tm = (tl + tr)/2;
    int resL = query(L(v), tl, tm, l, min(tm, r));
    int resR = query(R(v), tm+1, tr, max(tm+1, l), r);
    if (resL == -1) return resR;
    if (resR == -1) return resL;
    return height[resL] < height[resR] ? resL : resR;
  }

  int lca(int i, int j) {
    int l = first[i];
    int r = first[j];
    if (l > r) swap(l, r);
    return query(0, 0, eulerSize - 1, l, r);
  }

  LCA(int n, vvii &AL) : numNodes(n), AL(AL) {
    first.assign(n, 0);
    height.assign(n, 0);
    visited.assign(n, 0);
    euler.reserve(2 * n);
    DFS(0, 0);
    eulerSize = euler.size();
    T.assign(4 * eulerSize, 0);
    build(0, 0, eulerSize - 1);
  }

};

int main()  {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vvii AL(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    AL[u].emplace_back(v, w);
    AL[v].emplace_back(v, w);
  }
  LCA l(n, AL);
  while(true) {
    int u, v;
    cin >> u >> v;
    if (u == -1 && v == -1) break;
    cout << l.lca(u,v) << endl;
  }
}
