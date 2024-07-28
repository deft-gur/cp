#include <bits/stdc++.h>

using namespace std;

#define MX 100005

int b[MX];
int a[MX];

void solve() {
  int n;
  cin >> n;
  memset(a, 0, sizeof a);
  for (int i = 0; i < n-1; ++i) {
    cin >> b[i];
  }

  for(int i = 0; i < n-1; ++i) {
    // Take a look at b[i], a[i], a[i+1].
    a[i] = b[i] | a[i];
    a[i+1] = b[i] | a[i+1];
  }


  bool possible = true;
  for (int i = 0; i < n-1; ++i) {
    if (b[i] != (a[i] & a[i+1])) {
      possible = false;
      break;
    }
  }

  if (!possible) cout << -1;
  else for (int i = 0; i < n; ++i) cout << a[i] << " ";

  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
