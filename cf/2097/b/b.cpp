#include <bits/stdc++.h>

#define int long long

const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<vii>> vvvii;
int n, m, k;
vii points;
vii vertices;
vvi visited;
vvvii g;
int tests = 0;

int offset(int a) {
  if (a < 0) return -1;
  else if (a > 0) return 1;
  else return 0;
}

int dfsHelper(int x, int y, int &v, int &e) {
  //cout << "visiting " << x << y << endl;
  if (visited[x][y]) return 0;
  visited[x][y] = 1;
  ++v;
  int ret = 0;
  e += g[x][y].size();
  for (auto [cx, cy] : g[x][y]) {
    if (cx == x && cy == y) { ret = 1; }
    //cout << "trying to visit" << cx << cy << endl;
    ret = dfsHelper(cx, cy, v, e) || ret;
  }
  return ret;
}

int dfs(int x, int y) {
  //cout << x << y << endl;
  if (visited[x][y]) return 1;
  int v = 0, e = 0;
  int loop = dfsHelper(x, y, v, e);
  //if (e % 2 == 1) cout << "something is worng" ;
  //cout << e << endl;
  e = e/2;
  if (v == e && loop) return 1;
  else if (v == e) return 2;
  else if (v < e) return 0;
  else return v;
}

void solve() {
  cin >> n >> m >> k;
  points.assign(k+1, {0, 0});
  visited.assign(n+1, vi(m+1, 0));
  g.assign(n+1, vector<vii>(m+1, vii(0)));
  vertices.clear();
  int x, y;
  for (int i = 0; i < k+1; ++i) {
    cin >> x >> y;
    points[i].first = x;
    points[i].second = y;
  }
  for (int i = 0; i < k; ++i) {
    auto [x1, y1] = points[i];
    auto [x2, y2] = points[i+1];
    int xdist = x2 - x1;
    int ydist = y2 - y1;
    if (abs(xdist) == 1 && abs(ydist) == 1) {
      g[x1 + offset(xdist)][y1].push_back({x1, y1 + offset(ydist)});
      g[x1][y1 + offset(ydist)].push_back({x1 + offset(xdist), y1});
      vertices.push_back({x1, y1+offset(ydist)});
      vertices.push_back({x1+offset(xdist), y1});
    } else if ((abs(xdist) == 2 && ydist == 0) || (abs(ydist) == 2 && xdist == 0)) {
      g[x1 + offset(xdist)][y1 + offset(ydist)].push_back({x1 + offset(xdist), y1+offset(ydist)});
      g[x1 + offset(xdist)][y1 + offset(ydist)].push_back({x1 + offset(xdist), y1+offset(ydist)});
      vertices.push_back({x1 + offset(xdist), y1+offset(ydist)});
    } else {
     cout << 0 << endl;
     return;
    }
  }

  int ans = 1;
  for (auto [x, y] : vertices) {
    ans = (ans * dfs(x, y)) % mod;
  }
  cout << ans << endl;
}

int32_t main() {
  int t;
  cin >> t;
  while(t--) {
    ++tests;
    solve();
  }
}
