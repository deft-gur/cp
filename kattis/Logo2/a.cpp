#include <bits/stdc++.h>

using namespace std;
#define EPS 1e-9

struct vec {
  double x, y;
  vec() : x(0), y(0) {}
  vec(double _x, double _y) : x(_x), y(_y) {}
  vec operator-() { return {-x, -y}; }
};

vec operator*(double a, const vec &v) {
  return {v.x * a, v.y * a};
}

vec add(const vec &a, const vec &b) {
  return {a.x + b.x, a.y + b.y};
}

double dot(const vec &a, const vec &b) {
  return a.x * b.x + a.y * b.y;
}

double norm_sq(const vec &a) {
  return dot(a, a);
}

double dist(const vec &a) {
  return hypot(a.x, a.y);
}

double angleToRad(double deg) {
  return deg * M_PI / 180;
}

double radToAngle(double rad) {
  return rad * 180 / M_PI;
}

vec dirToVec(double deg) {
  double rad = angleToRad(deg);
  return {cos(rad), sin(rad)};
}

double vecToDir(const vec &v) {
  double x = v.x, y = v.y;
  double norm = sqrt(norm_sq(v));
  double rad = acos(x/norm);
  if (y < 0) rad = 2*M_PI - rad;
  return radToAngle(rad);
}

vec fd(const vec &v, double dist, double deg) {
  vec w = dirToVec(deg);
  //printf("deg, w: %lf %lf %lf\n", deg, w.x, w.y);
  //printf("dist * w, %lf %lf %lf %lf\n", w.x, w.y, (dist*w).x, (dist*w).y);
  return add(v, dist * w);
}

vec bk(const vec &v, double dist, double deg) {
  return fd(v, -dist, deg);
}

vec rotate(const vec &v, double theta) {
  double rad = angleToRad(theta);
  return {cos(rad) *  v.x - sin(rad) * v.y, sin(rad) * v.x + cos(rad) * v.y};
}

void solve() {
  int n;
  cin >> n;
  string command, x;
  vector<vec> V;
  V.assign(2, vec());
  vector<int> dir;
  dir.assign(2, 0);
  int idx = 0;
  string missing;
  for (int i = 0; i < n; ++i) {
    cin >> command >> x;
    if (x == "?") { 
      missing = command;
      if (command == "fd" || command == "bk") {
      } else {
	idx = 1;
      }
      continue;
    }
    int y = stoi(x);
    if (command == "fd") {
      //cout << "deg bfore" << dir[idx] << endl;
      V[idx] = fd(V[idx], y, (double)dir[idx]);
    } else if (command == "bk") {
      //cout << "deg bfore" << dir[idx] << endl;
      V[idx] = bk(V[idx], y, (double)dir[idx]);
    } else if (command == "lt") {
      dir[idx] = (dir[idx] + y) % 360;
    } else if (command == "rt") {
      dir[idx] = (dir[idx] - y) % 360;
    }
  }

  if (missing == "fd" || missing == "bk") {
    //printf("%lf %lf %lf %lf\n", V[0].x, V[0].y, V[1].x, V[1].y);
    double ans = dist(V[0]);
    cout << int(ans+EPS+0.5) << '\n';
  } else {
    double min = 10000;
    int minidx = 0;
    for (int i = 0; i < 360; ++i) {
      if (dist(add(V[0], rotate(V[1], dir[0] + i))) < min) {
	min = dist(add(V[0], rotate(V[1], dir[0] + i)));
	minidx = i;
      }
      if (dist(add(V[0], rotate(V[1], dir[0] + i))) < EPS) {
	cout << (missing == "lt" ? i : 360 - i) << endl;
	return;
      }
    }
    cout << (missing == "lt" ? minidx : 360 - minidx) << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
