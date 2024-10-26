#include <bits/stdc++.h>

#define EPS 1e-9
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

// ax+by+c = 0;
struct line {
  double a, b, c;
};

void pointsToLine(const point &p1, const point &p2, line &l) {
  if (fabs(p1.x - p2.x) < EPS) l = {1.0, 0.0, -p1.x};
  else
    l = {-(double)(p1.y-p2.y)/(p1.x-p2.x), 1.0, -(double)(l.a*p1.x) - p1.y};
}

void pointSlopeToLine(point p, double m, line &l) {
  l.a = -m;
  l.b = 1.0;
  l.c = -((l.a * p.x) + l.b * p.y);
}

bool areParallel(line l1, line l2) {
  return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

bool areSame(line l1, line l2) {
  return areParallel && (fabs(l1.c - l2.c) < EPS);
}

bool areIntersect(line l1, line l2, point &p) {
  if (areParallel(l1, l2)) return false;

  p.x = (l1.b*l2.c - l2.b*l1.c)/(l2.b*l1.a - l1.b*l2.a);

  // check b = 0, vertical line.
  if (fabs(l1.b) > EPS) p.y = -(l1.c - l1.a*p.x);
  else p.y = -(l2.c - l2.a*p.x);

  return true;
}

struct vec {
  double x, y;
  vec(double _x, double _y) : x(_x), y(_y) {}
};

// a -> b
vec toVec(const point &a, const point &b) {
  return vec(b.x - a.x, b.y - a.y);
}

vec scale (const vec &v, double s) {
  return vec(v.x*s, v.y*s);
}

point translate(const point &p, const vec &v) {
  return point(p.x+v.x, p.y+v.y);
}

double dot(const vec &v, const vec &w) {
  return v.x * w.x + v.y * w.y;
}

double norm_sq(const vec &v) {
  return dot(v, v);
}

double angle(const point &a, const point &o, const point &b) {
  vec oa = toVec(o, a), ob = toVec(o, b);
  return dot(oa, ob) / (sqrt(norm_sq(oa) * norm_sq(ob)));
}

double cross(const vec &a, const vec &b) { return a.x * b.y - a.y * b.x; }

// Recall a x b = |a||b| sin(theta) * n where n is a perpendicular vector to both a x b.
bool ccw(const point& p, const point &q, const point &r) {
  return cross(toVec(p, q), toVec(p, r)) > EPS;
}

bool collinear(const point &p, const point &q, const point &r) {
  return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

// Given a point p, and a line represneted by poitn a and b, find piont c on the line
// s.t. the distinace between c and p is minized.
double distToLine(const point &p, const point &a, const point &b, point &c) {
  vec ap = toVec(a, p), ab = toVec(a, b);
  // Calculate the proj_ab(ap) and the closest point would be a + proj_ab(ap)
  double u = dot(ap, ab) / norm_sq(ab);
  c = translate(a, scale(ab, u));
  return dist(c, p);
}

// Instead of a line of infinite length, now we are given a line with two end points.
double distToLineSegment(const point &p, const point &a, const point &b, point &c) {
  vec ap = toVec(a, p), ab = toVec(a, b);
  // Calculate the proj_ab(ap) and the closest point would be a + proj_ab(ap)
  double u = dot(ap, ab) / norm_sq(ab);
  if (u < 0.0) { c = point(a.x, a.y); return dist(a, p); }
  else if (u > 1.0) { c = point(b.x, b.y); return dist(b, p); }
  else return distToLine(p, a, b, c);
}

int main() {
  return 0;
}
