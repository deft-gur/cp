#include <iostream>

using namespace std;

void solve() {
  int n;
  int min = n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int l = 1;
  int r = n;
  while (l <= r) {
    int k = (r + l)/2;
    int ans = 0;
    for (int j = 0; j < k; ++j) ans |= a[j];
    int flag = false;
    for (int i = 1; i < n - k + 1; ++i) {
      int tmp = 0;
      for (int j = 0; j < k; ++j){
        tmp |= a[i + j];
      }
      if (tmp != ans) {
        l = k + 1;
        flag = true;
        break;
      }
    }
    if (!flag){
      min = k;
      r = k - 1;
    }
  }
  cout << l << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
}
