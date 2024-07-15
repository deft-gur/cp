#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define MXN 200005
int n;
int a[3][MXN];
ll target;
int t;
int d = 0;
 
 
void solve() {
  cin >> n;
  target = 0;
  for (int i = 0; i < 3; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
      if (i == 0) target +=a[i][j];
    }
  }

  int order[] = {0, 1, 2};
  do {
    int i = 0;
    ll acc = 0;
    int pos[3][2];
    int s = 1;
    for (int j = 1; j <= n; ++j) {
      acc += a[order[i]][j];
      if (acc >= (target+2)/3) {
	acc = 0;
	pos[order[i]][0] = s;
	pos[order[i]][1] = j;
	s = j+1;
	++i;
      }
      if (i == 3) {
	for (int k = 0; k < 3; ++k) {
	  for (int m = 0; m < 2; ++m) {
	    cout << pos[k][m] << " ";
	  }
	}
	cout << endl;
	return;
      }
    }
  } while(next_permutation(order, order+3));

  cout << -1 << endl;
}
 
int main() {
  cin >> t;
  while  (t--) {
    ++d;
    solve();
  }
}
