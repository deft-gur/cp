#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    if (n >= m && (n - m) % 2 == 0)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
