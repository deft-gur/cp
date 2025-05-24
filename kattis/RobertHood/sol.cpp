#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n;
vii pts;

float dist(ii a, ii b) {
  int distX = a.first - b.first;
  int distY = a.second - b.second;
  return hypot(distX, distY);
}

int cross(ii x, ii y) {
  return x.first * y.second - x.second * y.first;
}

ii operator-(ii x, ii y) {
  return make_pair(x.first - y.first, x.second - y.second);
}

int cross(ii x, ii y, ii c) {
  return cross(x - c, y - c);
}

vii CH(vii &pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  int sz = pts.size();
  vector<ii> ch;
  if (n < 3) {
    ch = pts;
    return ch;
  }

  for (int i = 0; i < sz; ++i) {
    while(ch.size() > 1 && cross(ch[ch.size() - 2], ch.back(), pts[i]) <= 0) ch.pop_back();
    ch.push_back(pts[i]);
  }

  int lowerConvex = ch.size();
  for (int i = n-2; i >= 0; --i) {
    while(ch.size() > lowerConvex && cross(ch[ch.size() - 2], ch.back(), pts[i]) <= 0) ch.pop_back();
    ch.push_back(pts[i]);
  }
  // Delete the repeated first point.
  ch.pop_back();
  return ch;
}

int main() {
  cin >> n;
  pts.assign(n, make_pair(0, 0));
  for (int i = 0; i < n; ++i) { int x, y; cin >> x >> y; pts[i] = make_pair(x, y); }

  float ans = 0;
  if (n < 3) {
    for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) ans = max(ans, dist(pts[i], pts[j]));
    printf("%.8f\n", ans);
  } else {
    // Calculate the extreme points of the convex hull and iterate through all possible pairs.
    vii hull = CH(pts);
    for (int i = 0; i < hull.size(); ++i) for (int j = 0; j < i; ++j) ans = max(ans, dist(hull[i], hull[j]));
    printf("%.8f\n", ans);
  }

  return 0;
}
