#include <bits/stdc++.h>

using namespace std;

inline int LSONE(int x) {
  return x & -x;
}

inline int update(int *a) {
  int largest = 0;
  for (int i = 0; i < 32; ++i) {
    if (a[i]) largest = i;
    if (abs(a[i]) == 2) {
      a[i+1] = a[i]/2;
      a[i] = 0;
    }
  }
  return largest;
}

void solve() {
  int x;
  cin >> x;
  int a[40];
  memset(a, 0, sizeof(int)*40);
  // Extract the bits of x
  int tz = 0;

  while (x) {
    int ls = LSONE(x);
    tz = __builtin_ctz(x);
    a[tz] = 1;
    x -= ls;
  }

  for (int j = 31; j > 0 ; --j) {
    if (a[j] && a[j-1]) {
      if (a[j] == 1 && a[j-1] == 1) {
        a[j-1] = -1;
        a[j] = 0;
        a[j+1] = 1;
        j+=3;
      } else if (a[j] == 1 && a[j-1] == -1) {
        a[j-1] = 1;
        a[j] = 0;
        j+=3;
      } else if (a[j] == -1 && a[j-1] == 1) {
        a[j-1] = -1;
        a[j] = 0;
        j+=3;
      } else if (a[j] == -1 && a[j-1] == -1) {
        a[j-1] = 1;
        a[j] = 0;
        a[j+1] = -1;
        j+=3;
      }
    }
  }

  cout << tz+2 << endl;
  for (int i = 0; i <= tz+1; ++i) {
    if (i) cout << " ";
    cout << a[i];
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while( t-- ) solve();
}
