#include <bits/stdc++.h>

using namespace std;

#define int long long

struct point {
  int x, y;
  point() : x(0), y(0) {}
  point(int _x, int _y) : x(_x), y(_y) {}
  point(const point &p) : x(p.x), y(p.y) {}
};

int dot(const point &v, const point &w) {
  return v.x * w.x + v.y * w.y;
}

int cross(const point &v, const point &w) {
  return v.x * w.y - v.y * w.x;
}

point toVec(const point &a, const point &b) {
  return {b.x - a.x, b.y - a.y};
}

point center;

void solve(int n) {
  vector<point> P;
  int x, y;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    P.emplace_back(x, y);
  }
  int a = 0, b = 0;
  center = {P[n/2]};
  point one = {1, 0};
  for (int i = 0; i < n; ++i) {
    point v = toVec(center, P[i]);
    int d = dot(one, v);
    int c = cross(one, v);
    if (d * c > 0) ++a;
    if (d * c < 0) ++b;
  }
  cout << a << " " << b << '\n';
}

int32_t main() {
  int n;
  while (cin >> n, n) { solve(n); }
}
