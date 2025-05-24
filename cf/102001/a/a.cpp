#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int zeros = 0, ones = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '0') ++zeros;
    else ++ones;
  }
  if (zeros > s.size() / 2) {
    cout << string(s.size(), '1') << endl;
  } else if (ones > s.size() / 2) {
    cout << string(s.size(), '0') << endl;
  } else {
    cout << (s[0] == '0' ? '1' : '0') + string(s.size()-1, s[0]) << endl;
  }
  return 0;
}
