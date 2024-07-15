#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int a[3];
    int left = 5;
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a+3);
    while (left) {
      int diff = a[1] - a[0] + 1;
      if (left >= diff) {
	 a[0] += diff;
	 left -= diff;
      } else {
	a[0] += left;
	left = 0;
      }
      if (a[0] > a[2]) swap(a[0], a[2]);
      else if (a[0] > a[1]) swap(a[0], a[1]);
    }
    cout << a[0] * a[1] * a[2] << endl;
  }
}
