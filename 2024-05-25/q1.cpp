#include <iostream>

using namespace std;

void solve() {
  int n;
  cin >> n;
  /* cout << "n" << n << endl; */
  int l, c;
  int first;
  cin >> l;
  first = l;
  bool ans = true;
  int i = 1;
  for (; i < n; ++i) {
    /* cout << "i" << i << endl; */
    cin >> c;
    /* cout << "c" << c << endl; */
    if (c < l) {
      l = c;
      break;
    }
    l = c;
  }

  if (i == n) {
    cout << "YES" << endl;
    return;
  }
  ++i;

  int largest = l;
  for (; i < n; ++i) {
    /* cout << "i" << i << endl; */
    cin >> c;
    /* cout << "c" << c << endl; */
    if (c < l) {
      l = c;
      break;
    }
    l = c;
    largest = l;
  }
  /* cout << "largest" << largest; */
  /* cout << "first" << first << endl; */

  if (i == n) {
    ans = largest <= first ? true : false;
  } else {
    ++i;
    ans = false;
    for (; i < n; ++i) cin >> c;
  }
  /* cout << "i" << i << endl; */
  cout << (ans ? "YES" : "NO") << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
