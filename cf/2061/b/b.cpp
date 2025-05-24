#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
vi a;
int n;

int main() {
  int t;
  cin >> t;
  while(t--) {
    cin >> n;
    a.assign(n, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end(), greater<>());
    bool noAns = false;
    int side = 0;
    for (int i = 0; i < n-1; ++i) {
      if (a[i] == a[i+1]) { side = a[i]; a.erase(a.begin()+i, a.begin()+i+2); break; }
      if (i == n-2) noAns = true;
    }
    int x = a[0], y = a[1];
    int len = a[0] - a[1];
    for (int i = 1; i < n-3; ++i) {
      if (len > a[i] - a[i+1]) {
	len = a[i] - a[i+1];
	x = a[i];
	y = a[i+1];
      }
    }
    if (len - 2*side >= 0) printf("-1\n");
    else printf("%d %d %d %d\n", side, side, x, y);
  }

}
