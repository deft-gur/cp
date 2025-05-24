#include <bits/stdc++.h>

using namespace std;
const int C = (int)5e4 + 5;
#define l(x) 2*x+1
#define r(x) 2*x+2
#define double long double

struct Line {
  double m, b;
  double operator() (double x) { return m * x + b; }
} a[C * 4];

void insert(int l, int r, Line seg, int idx) {
  if (l + 1 == r) {
    if (seg(l) > a[idx](l)) swap(a[idx], seg);
    return;
  }
  int mid = (l+r) >> 1;
  if (a[idx].m > seg.m) { swap(a[idx], seg); }
  if (a[idx](mid) < seg(mid)) {
    swap(a[idx], seg);
    insert(l, mid, seg, l(idx));
  } else {
    insert(mid, r, seg, r(idx));
  }
}

double query(int l, int r, int x, int idx) {
  if (l + 1 == r) {
    return a[idx](x);
  }
  int mid = (l+r) >> 1;
  if (mid > x) {
    return max(a[idx](x), query(l, mid, x, l(idx)));
  } else {
    return max(a[idx](x), query(mid, r, x, r(idx)));
  }
}

int main() {
  int n; cin >> n;
  while(n--) {
    string s;
    cin >> s;
    if (s == "Project") {
      double s, p;
      cin >> s >> p;
      insert(1, C, {p, s - p}, 0);
    } else {
      int t; cin >> t;
      cout << (int) (query(1, C, t, 0)/100) << '\n';
      //cout <<(query(1, C, t, 0)) << '\n';
    }
  }
}
