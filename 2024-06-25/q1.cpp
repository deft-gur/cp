#include <bits/stdc++.h>

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int x1, y1, x2, y2;
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    if ((x1 < y1 && x2 < y2) || (x1 > y1 && x2 > y2))
      printf("YES\n");
    else
      printf("NO\n");
  }
}
