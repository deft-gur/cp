#include <bits/stdc++.h>

//#define EPS 1e-9
#define EPS 1e-10
using namespace std;

struct point {
  double x, y;
  point() { x = y = 0.0; }
  point(double _x, double _y) : x(_x), y(_y) {}
  bool operator< (point other) const {
    if (fabs(x - other.x) > EPS) return x < other.x;
    return y < other.y;
  }
  bool operator= (point other) const {
    return (fabs(x - other.x) < EPS && fabs(y-other.y) < EPS);
  }
};

double dist(const point &p1, const point &p2) {
  return hypot(p1.x - p2.x, p1.y - p2.y);
}

double DEG_to_RAD(double d) { return d * M_PI / 180.0; }
double RAD_to_DEG(double d) { return d * 180.0 / M_PI; }

// rotate point CCW theta degree.
point rotate(const point &p, double theta) {
  double rad = DEG_to_RAD(theta);
  return point(p.x * cos(rad) - p.y * sin(rad),
	       p.x * sin(rad) + p.y * cos(rad));
}

int main() {
  vector<point> P;
  P.emplace_back(2e-9, 0);
  P.push_back({0, 2});
  P.push_back({1e-9, 1});
  sort(P.begin(), P.end());
  for (auto &pt : P) printf("%.9lf, %.9lf\n", pt.x, pt.y);
}
