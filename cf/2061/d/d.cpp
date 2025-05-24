#include <bits/stdc++.h>
 
using namespace std;
typedef vector<int> vi;
typedef map<int, int> mi;
typedef set<int, greater<int>> si;
int n, m;
int newn, newm;
mi amap, bmap;
vi a, b;
si sa, sb;
 
void solve() {
  cin >> n >> m;
  a.assign(n, 0); b.assign(m, 0);
  amap.clear(), bmap.clear();
  sa.clear(), sb.clear();
  for (int i = 0; i < n; ++i) { cin >> a[i]; ++amap[a[i]]; sa.insert(a[i]); }
  for (int i = 0; i < m; ++i) { cin >> b[i]; ++bmap[b[i]]; sb.insert(b[i]); }
 
  sort(b.begin(), b.end(), greater<int>());
  int count = n - m;
  for (int i = 0; i < count; ++i) {
    if (sb.empty()) break;
    int bval = *sb.begin();
    if (bval == 1) break;
    if (bmap[bval] != amap[bval]) {
      ++bmap[floor(bval/2.0f)];
      ++bmap[ceil(bval/2.0f)];
      --bmap[bval];
      if (bmap[bval] == 0) sb.erase(sb.begin());
      sb.insert(ceil(bval/2.0f));
      sb.insert(floor(bval/2.0f));
    } else { sb.erase(sb.begin()); --i; }
  }
 
  int ans = 1;
  for (const auto &[key, val] : bmap) {
    if (val != amap[key]) { ans = 0; break; }
  }
  for (const auto &[key, val] : amap) {
    if (val != bmap[key]) { ans = 0; break; }
  }
 
  cout << (ans ? "YES" : "NO") << endl;
}
 
int main() {
  int t; cin >> t;
  while(t--) {
    solve();
  }
}
