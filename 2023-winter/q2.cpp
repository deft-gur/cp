#include <bits/stdc++.h>

using namespace std;

#define pi pair<int, int>

void solve() {
  int n;
  scanf("%d", &n);
  int x, y;
  int quad1, quad2, quad3, quad4, xpos, xneg, ypos, yneg;
  quad1 = quad2 = quad3 = quad4 = xpos = xneg = ypos = yneg = 0;
  set<pi> pts;
  for (int i =0; i <n; ++i) {
    scanf("%d %d", &x, &y);
    pts.insert({x, y});
    if (x == 0) {
      if (y > 0) {
        ++ypos;
      } else {
        ++yneg;
      }
    } else if (y == 0) {
      if (x > 0) {
        ++xpos;
      } else {
        ++xneg;
      }
    } else if (x > 0 && y > 0) {
      ++quad1;
    } else if (x < 0 && y > 0) {
      ++quad2;
    } else if (x < 0 && y < 0) {
      ++quad3;
    } else {
      ++quad4;
    }
  }

  int m = 0;
  m = min(quad1 + quad2, quad2 + quad3);
  m = min(m, quad4 + quad1);
  m = min(quad3 + quad4, m);
  m += min(xpos, xneg);
  m += min(ypos, yneg);
  printf("%d\n", m);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();

}
