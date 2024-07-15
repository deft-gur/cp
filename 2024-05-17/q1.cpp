#include <iostream>

using namespace std;
void sort(int *a, int *b, int *c) {
  /* printf("before;%d %d %d\n", *a, *b, *c); */
  if (*a >= *b) swap(*a,*b);
  if (*b >= *c) swap(*b,*c);
  /* printf("after;%d %d %d\n", *a, *b, *c); */
}

void solve() {
  int p1, p2, p3;
  scanf("%d %d %d", &p1, &p2, &p3);
  if ((p2 + p1 + p3)  % 2 != 0) {
    printf("-1\n");
    return;
  };
  int draws = 0;
  while(p3 && p2) {
    --p3; --p2; ++draws;
    sort(&p1, &p2, &p3);
  }
  printf("%d\n", draws);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    solve();
  }
}
