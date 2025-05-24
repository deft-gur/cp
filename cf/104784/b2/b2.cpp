#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  int ans = 0;
  while(cin >> s) {
    if (s[0] == '|') {
      ans += 42 * s.length();
    } else {
      stringstream ss(s);
      int price;
      ss >> price;
      string tmp;
      ss >> tmp;
      if (tmp.length() == 2) ans += price;
      else ans += price * (tmp.length()-2);
    }
  }
  cout << (ans) + ((10 - (ans % 10)) % 10) << ",-" << endl;
}
