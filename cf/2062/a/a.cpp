#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
vi zeroed;

int main() {
  int t;
  cin >> t;
  while(t--) {
    string s; cin >> s;
    int ans = 0;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') continue;
      int len = 1;
      int j = i+1;
      int zero = true;
      zeroed.assign(n, 0);
      zeroed[i] = 1;
      for (; j < n; ++j) {
	if (zero && s[j] == '0') { zero = !zero; zeroed[j] = 1; ++len; }
	else if (!zero && s[j] == '1') { zero = !zero; zeroed[j] = 1; ++len; }
      }
      ans += (len+1)/2;
      //cout << "Len" << len << endl;
      for (int k = 0; k < n; ++k) {
	if (zeroed[k] == 1) s[k] = '0';
      }
    }
    cout << ans << endl;
  }
}
