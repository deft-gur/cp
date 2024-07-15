#include <iostream>

using namespace std;

void solve() {
  int x,y;
  cin >> x >> y;
  int ans  = y % 2 == 0 ? y/2 : y/2 + 1;
  /* cout << "ans: " << ans << endl; */
  int stillNeeded = ans * 15 - y * 4;
  stillNeeded = x - stillNeeded;
  /* cout << "stillNeeded: " << stillNeeded << endl; */
  if (stillNeeded > 0) {
    ans += stillNeeded % 15 == 0 ? stillNeeded/15 : stillNeeded/15 + 1;
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
