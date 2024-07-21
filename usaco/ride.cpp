/*
ID: ziwenhe1
LANG: C++
TASK: ride
*/

#include <bits/stdc++.h>

using namespace std;

const int mod = 47;

int main() {
  ifstream fin("ride.in");
  ofstream fout("ride.out");
  string a, b;
  fin >> a >> b;
  int x, y;

  x = 1, y = 1;

  for (int i = 0; i < a.size(); ++i) {
    x = (x * (a[i] - '@')) % mod;
  }

  for (int i = 0; i < b.size(); ++i) {
    y = (y * (b[i] - '@')) % mod;
  }
  fout << ((y == x) ? "GO" : "STAY") << endl;
  
  return 0;
}
