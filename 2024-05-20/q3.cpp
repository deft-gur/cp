#include <iostream>
#include <vector>

#define ll long int
using namespace std;

ll v[200000];


inline bool checkBeautiful(int i, int j) {
  if (v[i] != v[j] && v[i+1] == v[j+1] && v[i+2] == v[j+2])
    return 1;
  else if (v[i] == v[j] && v[i+1] != v[j+1] && v[i+2] == v[j+2])
    return 2;
  else if (v[i] == v[j] && v[i+1] == v[j+1] && v[i+2] != v[j+2])
    return 3;
  else
    return 0;
}

void solve() {
  int n;
  cin >> n;
  ll a[n][3];
  int ans = 0;
  for (int i = 0; i < n; ++i){
    cin >> v[i];
    if (i >= 3) {
      for (int j = i - 3; j >= 0; --j) {
        int b = checkBeautiful(i-2, j);
        if (a[j][b] == 0)
          a[j][b] = a[i-2][b]+1;
        if (checkBeautiful(i-2,j)){
          ++ans;
        } else {
        }
      }
    }
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
