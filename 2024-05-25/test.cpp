#include <bits/stdc++.h>

using namespace std;

int main() {
  int a[] = {1, 2, 3, 4};
  sort(a, a+4);
  do {
    for (int i = 0; i < 4; ++i) {
      cout << (i ? " " : "");
      cout << a[i];
    }
    cout << endl;
  }while(next_permutation(a, a+4));
}
