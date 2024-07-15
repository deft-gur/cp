#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

#define dim 51

// Recall that we need \n and \0. So two extra chars.
static const char face[dim][dim+2] = 
 {
    "@XXXXXXXXX@XXXXXXXXX@XXXXXXXXX@XXXXXXXXX@XXXXXXXXX@\n",
    "X                                                 X\n",
    "X                       1 2                       X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "@                                                 @\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "@                                                 @\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X 9                      *                      3 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "@                                                 @\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "@                                                 @\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                        6                        X\n",
    "X                                                 X\n",
    "@XXXXXXXXX@XXXXXXXXX@XXXXXXXXX@XXXXXXXXX@XXXXXXXXX@\n"
};
static char buffer[dim][dim+2];

static inline int zaok(double x) {
  return x > 0 ? (int) x +0.5 : x - 0.5;
}
void getCord(int angle, int *x, int *y, int i) {
  if (90 < angle && angle < 270) {
    *x = i;
    *y = zaok(tan(180 - angle) * M_PI/360);
  }
}

void segment(int angle,int l) {
  // lch : last char
  // nch : next char
  // ch  : current char
  int x, y, lch=0, nch, ch;
  for(int i = 1; ; ++i) {
    getCord(angle, &x, &y, i);
    if (x * x + y * y > l) return;
  }
}

void solve(int h, int m) {
  memcpy(buffer, face, sizeof(face));
  h = h % 12;
  segment(h * 12, 15);
  segment(m * 60, 21);

  for (int i = 0; i < dim; ++i) {
    printf("%s", buffer[i]);
  }
  printf("%s", "\n");
}

int main() {
  int h, m;
  while (scanf("%d:%d", &h, &m)) {
    solve(h,m);
  }
}
