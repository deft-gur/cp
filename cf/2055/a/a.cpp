#include <bits/stdc++.h>

using namespace std;

int main() {
  int t, n, a, b;
  cin >> t;
  while(t--) {
    cin >> n >> a >> b;
    //cout << a << ", " << b << endl;
    //cout << (a - b + 1) % 2 << endl;
    if ((a - b + 1) % 2) cout << "YES";
    else cout << "NO";
    cout << '\n';
  }

}
