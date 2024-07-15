#include <iostream>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int m1 = 0, m2 = 0;
  int c = 0;
  cin >> m1 >> m2;
  int last = m2;
  if (m1 < m2) swap(m1, m2);
  for (int i = 2; i < n; ++i) {
    cin >> c;
    if (i == n - 1) last = c;
    if (c > m1) {
      swap(m1, m2);
      m1 = c;
    }
    /* }else if (c > m2) { */
    /*   m2 = c; */
    /* } */
  }
  cout << (last != m1 ? m1 : m2) << endl;
}

int main() {
  int t;
  cin >> t;
  while( t-- ) solve();
}
