#include <iostream>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  int mx;
  // Query the max in the array:
  for (int i = 1; i <= n; ++i) {
    int r;
    cout << "? " << 1 << " " << (i * n) << endl;
    cout.flush();
    cin >> r;
    if (r == n) {mx = i; break;}
  }
  // Since we know mx. Then the possible values of m is mx, 2mx, ..., nmx
  // But since k * i * mx <= n * mx
  // We have: i <= n/k.
  // For each choices of i = 1, ..., n/k. We at most query k times to determine
  // if it is feasible or not.
  for (int i = 1; i <= n/k; ++i) {
    int l = 1;
    int r;
    for (int j =  0; j < k; ++j) {
      cout << "? " << l << " " << i * mx << endl;
      cout.flush();
      cin >> r;
      if (r == n+1) break;
      l = r + 1;
      if (l == n+1 && j + 1 < k) break;
      else if (l == n + 1 && j + 1 == k){
        cout << "! " << i * mx << endl;
        cout.flush();
        return;
      }
    }
  }
  cout << "! " << -1 << endl;
  cout.flush();
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int tmp;
    solve();
    cin >> tmp;
    if (tmp == -1) exit(1);
  }
}
