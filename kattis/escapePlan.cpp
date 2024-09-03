#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<float, float> ff;
typedef vector<ff> vff;

const float eps = 1e-6;
const float speed = 10;
int m, n;
vff robots, holes;
vector<vi> AL;
vector<int> L, R, vis;

int aug(int l) {
  if (vis[l]) return 0;
  vis[l] = 1;
  for (auto r : AL[l]) {
    if (R[r] == -1 || aug(R[r])) { R[r] = l; L[l] = r; return 1; }
  }
  return 0;
}

int maxmatch(float seconds) {
  AL.assign(m, vi());
  L.assign(m, -1);
  R.assign(n, -1);
  int ans = 0;

  float x1, x2, y1, y2;
  for (int i = 0; i < m; ++i) {
    tie(x1, y1) = robots[i];
    for (int j = 0; j < n; ++j) {
      tie(x2, y2) = holes[j];
      float d = hypot(x1 - x2, y1 - y2);
      if (seconds * speed < d) continue;
      AL[i].push_back(j);
    }
  }

  while (true) {
    bool updated = false;
    vis.assign(m, 0);
    for (int i = 0; i < m; ++i) {
      if (L[i] == -1) { 
	int tmp = aug(i);
	if (tmp) updated = true;
	ans += tmp;
      }
    }
    if (!updated) break;
  }
  return ans;
}


int main() {
  int it = 1;
  do {
    cin >> m;
    if (!m) break;
    robots.clear();
    holes.clear();
    float x, y;
    for (int i = 0; i < m; ++i) { cin >> x >> y; robots.emplace_back(x, y); }
    cin >> n;
    for (int i = 0; i < n; ++i) { cin >> x >> y; holes.emplace_back(x, y); }
    printf("Scenario %d\n", it);
    printf("In %d seconds %d robot(s) can escape\n", 5, maxmatch(5));
    printf("In %d seconds %d robot(s) can escape\n", 10, maxmatch(10));
    printf("In %d seconds %d robot(s) can escape\n", 20, maxmatch(20));
    printf("\n");
    ++it;
  } while(true);
  
}
