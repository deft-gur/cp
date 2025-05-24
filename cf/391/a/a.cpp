#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int start = 0;
  int j = 0;
  int ans = 0;
  while(start < s.length()) {
    while(j+1 < s.length() && s[j] == s[j+1]) {
      ++j;
    }
    if ((j - start) % 2 == 1) ++ans;
    start = ++j;
  }
  cout << ans << endl;
}
