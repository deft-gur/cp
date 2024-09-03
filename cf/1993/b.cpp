#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef vector<int> vi;


void solve() {
  int n;
  cin >> n;
  vi odd, even;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x % 2) odd.push_back(x);
    else even.push_back(x);
  }
  sort(even.begin(), even.end());
  auto mxIt = max_element(odd.begin(), odd.end());
  if (mxIt == odd.end()) {
    cout << 0 << endl;
    return;
  }
  int mx = *mxIt;

  int ans = 0;
  int end = even.size();
  for (int i = 0; i < end; ++i) {
    //cout << "before mx: " << mx << endl;
    if (even[i] > mx) {
      mx += 2 * even[even.size() - 1];
      end -= 1;
      ans += 2;
      --i;
    } else {
      mx += even[i];
      ++ans;
    }
    //cout << "after mx: " << mx << endl;
  }
  cout << ans << endl;
}

int32_t main() {
  int t;
  cin >> t;
  while(t--) solve();
}
