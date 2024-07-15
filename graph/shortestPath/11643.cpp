#include <bits/stdc++.h>

using namespace std;

#define MXN 1004
#define MXK 20
int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

int dist[MXN][MXN];
int interDist[MXK][MXK];
ii interPoint[MXK];
int n, k;

void bfs() {
  queue<ii> q;
  p.emplace(0, 0);
  dist[0][0] = 0;
  memset(dist, -1, sizeof dist);
  while(!q.empty()) {
    auto [x, y] = q.top();
    q.pop();
    for (int i = 0; i < 8; ++i) {
      int u = x + dx[i], v = y + dy[i];
      if (u < n && v < n && u >= 0 && v > 0 && dist[u][v] == -1) {
	d[u][v] = d[x][y] + 1;
	q.emplace(u,v);
      }
    }
  }
}

// Find a minimum cycle that visits every node (travling sales man problem).
void dp() {

}

void solve(int i) {
  cin >> n >> k;
  memset(dist, 0, sizeof dist);
  memset(interDist, 0, sizeof interDist);
  bfs();
  for (int i = 0; i < k; ++i) {
    int r, c;
    cin >> r >> c;
    --r, --c;
    interPoint[i] = {r, c};
  }

  // Calculate the distance between every intersection point.
  for (int i = 0; i < k; ++i) {
    for (int j = i + 1; j < k; ++j) {
      int xdiff = abs(interPoint[i].first - interPoint[j].first);
      int ydiff = abs(interPoint[i].second - interPoint[j].second);
      interDist[i][j] = interDist[j][i] = dist[xdiff][ydiff];
    }
  }

  dp();

  cout << "Case " << i << ":" << ? << endl;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    solve(i);
  }
}
