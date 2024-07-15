#include <bits/stdc++.h>

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int x, y, k;
    scanf("%d %d %d", &x, &y, &k);
    while (k > 0 && x!= 1) {
      int tmp = (y - x%y) % y;
      if (k < tmp) {
	x += k;
	k = 0;
	break;
      }
      x += tmp;
      k -= tmp;
      while(x % y == 0) {
	x /=y;
      }
    }
    if (k > 0) {
      x = (k) % (y-1) + 1;
    }

    printf("%d\n", x);
  }
}
