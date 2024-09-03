#include <bits/stdc++.h>

using namespace std;
#define int long long
#define EPS 1e-9

int EEA(int a, int b, int &x, int &y) {
  int origA, origB;
  origA = a; origB = b;
  int yy, xx;
  x = yy = 1;
  y = xx = 0;
  while (b) {
    int t, q;
    q = a/b;
    t = b; b = a - q * b; a = t;
    t = xx; xx = x - q * xx; x = t;
    t = yy; yy = y - q * yy; y = t;
    q = xx/origB;
    xx = xx%origB;
    yy = yy - origA*q;
  }

  return a;
}

int32_t main() {
  double aa, bb, cc;
  int a, b, c;
  cin >> cc >> aa >> bb;
  c = cc * 100 + EPS;
  b = bb * 100 + EPS;
  a = aa * 100 + EPS;
  int x, y;
  int g = EEA(a, b, x, y);

  int q;
  if (c % g != 0) { cout << "none" << endl; return 0; }
  q = c/g;
  x *= q;
  y *= q;
  q = x / b;
  x = x % b;
  y = y + a*q;
  // ax + by = g
  // x = x + b/g t, y = y - a/g t
  // x >= 0 -> t >= -x*g/b
  // y >= 0 -> t <= y*g/a
  for (int t = ceil((double)(-x*g)/b); t <= floor((double)(y*g)/a); ++t) {
    cout << (x + b/g*t) << " " << (y - a/g*t) << '\n';
  }
}
