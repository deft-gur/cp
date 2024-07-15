#include <bits/stdc++.h>

using namespace std;

typedef pair<float, float> ff;
typedef vector<ff> vff;
typedef vector<tuple<float, int, int>> vfii;
typedef vector<int> vi;

inline float dist(float x1, float y1, float x2, float y2) {
  float xdist = x1 - x2;
  float ydist = y1 - y2;
  return sqrt(xdist * xdist + ydist * ydist);
}

class UnionFind {
private:
  int size;
  vi p;
  int numSet;
  vi rank;

public:
  UnionFind(int n) :size(n), p(n), numSet(n), rank(n) {
    for (int i = 0; i < n; ++i) p[i] = i;
  }

  int whichSet(int i) {
    return (p[i] == i) ? i : p[i] = whichSet(p[i]);
  }
  bool isSame(int i, int j) { return whichSet(i) == whichSet(j);}

  void join(int i, int j) {
    if (isSame(i, j)) return;
    int x = whichSet(i), y = whichSet(j);
    if (rank[x] > rank[y]) swap(x, y);
    p[x] = y;
    if (rank[x] == rank[y]) ++rank[y];
    --numSet;
  }
};

void solve() {
  int m;
  scanf("%d", &m);
  vff coord(m);
  for (int i = 0; i < m; ++i) {
    float x, y;
    scanf("%f %f", &x, &y);
    coord[i] = {x, y};
  }
  vfii EL;
  for (int i = 0; i < m; ++i) {
    auto [x1, y1] = coord[i];
    for (int j = i+1; j < m; ++j) {
      auto [x2, y2] = coord[j];
      float w = dist(x1, y1, x2, y2);
      //printf("%f %f %f %f %f \n", w, x1, y1, x2, y2);
      EL.emplace_back(w, i, j);
    }
  }

  sort(EL.begin(), EL.end());

  UnionFind UF(m);
  float ans = 0;
  int edge = 0;
  for (int i = 0; i < EL.size(); ++i) {
    auto [w, u, v] = EL[i];
    //printf("%f %d %d\n", w, u, v);
    if (UF.isSame(u, v)) continue;
    ans += w;
    UF.join(u,v);
    if (++edge == m-1) break;
  }
  printf("%f\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();

}
