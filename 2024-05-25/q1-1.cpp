#include <bits/stdc++.h>

using namespace std;
int main() {
  int n;
  cin >> n;
  //int a[n];
  vector<int> a(n);
  for (int i= 0; i < n; ++i) cin >> a[i];

  rotate(a.begin(), a.begin() + 1, a.end());

  for (int i = 0; i < n; ++i) {
    cout << a[i] << ",";
  }

  cout << endl;

}
