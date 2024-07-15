#include <bits/stdc++.h>

using namespace std;

#define pi pair<int, int>
#define vii vector<pi>
#define vi vector<int>

#define mx 100000+5
vi vis(mx);
vii edges(mx);
vi edgesInvert[mx];
vi neighbours[mx];
int n, m;
int root[mx];

int fdRoot(int x) {
  if (root[x] == x) return x;
  else return root[x] = fdRoot(root[x]);
}

int bfs() {
  for (int i = 1; i < n + 1; ++i) {
    root[i] = i;
  }

  for (int i = 0+1; i < m+1; ++i) {
    int x = edges[i].first;
    int y = edges[i].second;
    neighbours[x].push_back(y);
    neighbours[y].push_back(x);
    edgesInvert[x].push_back(i);
    edgesInvert[y].push_back(i);
    int rtX = fdRoot(x); 
    int rtY = fdRoot(y);
    if (rtX == rtY) return i;
    root[rtX] = rtY;
  }
  return -1;
}

int findPath(int s, int t, vi &path) {
  vis[s] = 1;
  for (int i = 0; i < neighbours[s].size(); ++i) {
    int e = neighbours[s][i];
    if (vis[e]) continue;

    if (e == t){
      path.push_back(edgesInvert[s][i]);
      return 1;
    }
    else if(findPath(e, t, path)) {
      path.push_back(edgesInvert[s][i]);
      return 1;
    }
  }
  return 0;
}

void solve() {
  scanf("%d %d", &n, &m);

  for (int i = 1; i < n+1; ++i) {
    edgesInvert[i].clear();
    neighbours[i].clear();
  }
  fill(vis.begin(), vis.begin() + n+1, 0);
  edges.clear();
  edges.resize(mx);

  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    edges[i] = {x, y};
  }
  int e = bfs();
  if (e == -1) {
    printf("-1\n");
    return;
  }

  fill(vis.begin(), vis.begin() + n+1, 0);
  vi p;
  findPath(edges[e].first, edges[e].second, p);
  p.push_back(e);
  sort(p.begin(), p.end());
  for (int i = 0; i < p.size(); ++i) {
    printf("%d%c", p[i], "\n "[i != p.size() - 1]);
  }
  return;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}
