#include <bits/stdc++.h>

using namespace std;
int n, m;

int left(int x) {
  int i = x % (2*m);
  if (i < m) return 1;
  else return 0;
}

int solve() {
  cin >> n >> m;
  int cnt = 0, leftCnt = 0, rightCnt = 0;
  for (int i = 0; i < 2 * n * m; ++i) {
    int x;
    cin >> x;
    --x;
    if (cnt - leftCnt - rightCnt != (x/(2*m))*2*m) {
      return 0;
    }

    if (left(x)) {
      int i = x % (m);
      //cout << x << endl;
      //cout << "left" << endl;
      if (m-i-1 != leftCnt) return 0;
      ++leftCnt;
    } else {
      int i = x % (m);
      //cout << x << endl;
      //cout << "right" << endl;
      if (i != rightCnt) return 0;
      ++rightCnt;
    }
    ++cnt;
    if (leftCnt == m && rightCnt == m) {
      leftCnt = rightCnt = 0;
    }
  }
  return 1;
}

int main() {
  cout << (solve() ? "yes" : "no") << endl;
}
