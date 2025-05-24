#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
vi cnt;
string s;
map<string, int> m;


int main() {
  int t; cin >> t;
  m["A"] = 0;
  m["B"] = 1;
  m["AB"] = 2;
  m["BA"] = 3;
  while(t--) {
    cin >> s;
    cnt.assign(4, 0);
    int n = s.size();
    for (int i = 0; i < 4; ++i) cin >> cnt[i];
    for (int i = 0; i < n; ++i) {
      string tmp = s.substr(i, 2);
      if (i != n-1 && m.find(tmp) != m.end() && cnt[m[tmp]] > 0) {
	--cnt[m[s.substr(i,2)]];
	++i;
      } else {
	--cnt[m[s.substr(i, 1)]];
      }
      for (int i = 0; i < 4; ++i) {
	cout << cnt[i] << ",";
      }
      cout << endl;

    }

    int ok = true;
    for (int i = 0; i < 4; ++i) {
      if (cnt[i] < 0) ok = false;
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}
