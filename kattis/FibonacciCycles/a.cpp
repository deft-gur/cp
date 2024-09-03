#include <bits/stdc++.h>

using namespace std;
#define MX 1000

int A[MX];

int main() {
  int Q;
  int mod;
  cin >> Q;
  while(Q--) {
    cin >> mod;
    memset(A, 0, sizeof A);
    int Fi, Fi1;
    Fi = Fi1 = 1;
    int n = 2;
    while(true) {
      swap(Fi1, Fi);
      Fi1 = (Fi1 + Fi) % mod;
      if (A[Fi1]) { cout << A[Fi1] << endl; break; }
      A[Fi1] = n;
      ++n;
    }
  }
}
