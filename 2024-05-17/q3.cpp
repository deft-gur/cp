#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) {
    cin >> i;
  }

  int nIdx = (find(a.begin(), a.end(), n) - a.begin()) % 2;
  vector<pair<int,int>> nArray;
  vector<pair<int,int>> bArray;
  for (int i = nIdx; i < n; i+=2) {
    nArray.push_back({a[i], i});
  }
  for (int i = (nIdx ^ 1); i < n; i+=2) {
    bArray.push_back({a[i], i});
  }
  sort(nArray.begin(), nArray.end());
  sort(bArray.begin(), bArray.end());
  reverse(nArray.begin(), nArray.end());
  reverse(bArray.begin(), bArray.end());

  int cnt = 0;
  vector<int> q(n);
  for (auto v : bArray) q[v.second] = ++cnt;
  for (auto v : nArray) q[v.second] = ++cnt;
  for (int i = 0; i < n; ++i) cout << q[i] << " \n"[i + 1 == n];
}

int main() {
  int t;
  cin >> t;
  while(t--)
    solve();
}
