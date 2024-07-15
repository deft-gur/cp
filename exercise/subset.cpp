#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) cin >> a[i];

  int mask = 0;
  for (int i = 0; i < (1 << n); ++i) {
    for (int j = 0; j < n; ++j) {
      if (i & (1 << j)) printf("%d, ", a[j]);
    }
    printf("\n");
  }
}
