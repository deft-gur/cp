#include <bits/stdc++.h>

using namespace std;

int main() {
  int y;
  while(cin >> y) {
    if (y == 0) break;
    int bits = pow(2, (y - 1960)/10 + 2);
    int ans = 3;
    double fact = log2(3) + log2(2);
    while(true) {
      if (fact > bits) break;
      fact += log2(++ans);
    }
    cout << --ans << endl;
  }
}
