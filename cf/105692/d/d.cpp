#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int n;
vvi a;

int main() {
  int t;
  cin >> t;
  while(t--) {
    cin >> n;
    a.assign(n, vi(n, 0));
    a[0][0] = 1;
    for (int i = 1; i < n; ++i) {
      a[0][i] = 2*(i);
    }
    for (int i = 1; i < n; ++i) {
      a[i][0] = 2*(i) + 2*(n-1);
    }
    int nxt = 3;
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < n; ++j) {
	a[i][j] = nxt;
	if (nxt < 4*(n-1)) nxt += 2;
	else ++nxt;
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) cout << a[i][j] << " "; 
      cout << endl;
    }
  }
}
