#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int main() {
  int t;
  cin >> t;
  vi v;
  while(t--) {
    int n;
    cin >> n;
    v.assign(n, 0);
    v[0] = 1;
    v[1] = 1;
    for (int i = 2; i < n-2; ++i) {
      v[i] = i;
    }
    v[n-2] = 1;
    v[n-1] = 2;
    for (int i = 0; i < n; ++i) {
      cout << v[i] << " ";
    }
    cout << '\n';
  }
}
