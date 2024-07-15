#include <iostream>
#include <vector>

#define ll long int
using namespace std;

vector<ll> v;

bool checkBeautiful(int i, int j) {
  return (v[i] != v[j] && v[i+1] == v[j+1] && v[i+2] == v[j+2]) ||
         (v[i] == v[j] && v[i+1] != v[j+1] && v[i+2] == v[j+2]) ||
         (v[i] == v[j] && v[i+1] == v[j+1] && v[i+2] != v[j+2]);
}

void solve() {
  v.clear();
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i){
    ll a;
    cin >> a;
    v.push_back(a);
  }
  int ans = 0;
  for (int i = 0; i < n - 2; ++i)  {
    for (int j = i+1; j < n - 2; ++j) {
      if (checkBeautiful(i,j)){
        ++ans;
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
