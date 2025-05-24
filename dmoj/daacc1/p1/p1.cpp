#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  if (n == m || n+1 == m) {
    cout << "stressed";
  } else if (m > n) {
    cout << "okay";
  } else {
    cout << "relaxed";
  }
  cout << '\n';
}
