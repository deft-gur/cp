#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
int n;
vi s, a;

int main() {
  int t;
  cin >> t;
  while(t--) {
    cin >> n;
    s.assign(n, 0);
    for (int i = 1; i < n-1; ++i) cin >> s[i];
    a.assign(n, -1);
    if (s[1] == 0) {
      a[0] = 0; a[1] = 1;
    } else {
      a[0] = a[1] = a[2] = 1;
    }

    int ans = 1;
    for (int i = 2; i < n-1; ++i) {
      if (s[i] == 0) {
	if (a[i-1] == -1) {
	  a[i] = 0; a[i-1] = 1;
	} else if (a[i] == -1) {
	  a[i] = a[i-1] ^ 1;
	} else if (a[i] == a[i-1]) {
	  a[i+1] = a[i]^1;
	}
      } else {
	if (a[i-1] == -1) a[i-1] = 0;
	if (a[i-1] != -1 && a[i] != -1 && a[i] != a[i-1]) { ans = 0; break; }
	a[i+1] = a[i] = a[i-1];
      }
    }
    //for (int i = 0; i < n; ++i) {
    //  cout << a[i] << ' ';
    //}
    //cout << endl;
    cout << (ans ? "yes" : "no") << endl;
  }
}
