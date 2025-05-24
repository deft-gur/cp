#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
int n, k;
string a;

int main() {
  cin >> n >> k;
  cin >> a;
  //cout << a << endl;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    bool skip = false;
    int j = min(i+k, n-1);
    for (; j >= i; --j) {
      if (a[j] == '1') {
        i = j+k;
        skip = true;
        break;
      }
    }
    if (skip) continue;
    ++ans;
    i = i+2*k;
  }
  //cout << a << endl;
  cout << ans << endl;
}
