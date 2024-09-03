#include <bits/stdc++.h>

using namespace std;
#define EPS 1e-8

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long double X, Y, N, r;
  while(true) {
    cin >> X >> Y >> N >> r;
    if (X == 0) break;
    long double n = N*12;
    long double rate = (1 + r/1200);
    long double ans;
    if (r/1200 < EPS) {
      ans = X - n * Y;
      cout << (ans <= EPS ? "YES" : "NO") << endl;
      continue;
    }
    ans = (X * pow(rate, n) - Y * (pow(rate, n) - 1)/(r/1200));
    cout << (ans <= EPS ? "YES" : "NO") << endl;
  }
}
