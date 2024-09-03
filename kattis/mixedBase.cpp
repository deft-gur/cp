#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

struct mixed{
  enum type {ten, twentysix, Twentysix };
  vector<type> types;
  vi digits;

  type getType(char c) {
    if ('0' <= c && c <= '9') {
      return ten;
    } else if ('a' <= c && c <= 'z') {
      return twentysix;
    } else { 
      return Twentysix;
    }
  }

  int getInt(char c) {
    type t = getType(c);
    if (t == ten) return c - '0';
    else if (t == twentysix) return c - 'a';
    else return c - 'A';
  }

  char getChar(int i, type t) {
    if (t == ten) return '0' + i;
    else if (t == twentysix) return 'a' + i;
    else return 'A' + i;
  }

  int getMod(type t) {
    if (t == ten) return 10;
    else return 26;
  }

  string getString() {
    string ans(digits.size(), '0');
    for (int i = 0; i < digits.size(); ++i) {
      ans[i] = getChar(digits[i], types[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }

  mixed(string s) {
    reverse(s.begin(), s.end());
    for (char c : s) {
      types.push_back(getType(c));
      digits.push_back(getInt(c));
    }
  }

  void add(int a) {
    int q = a;
    int r = 0;
    for (int i = 0; i < digits.size(); ++i) {
      int mod = getMod(types[i]);
      r = q % mod;
      q = (digits[i] + q) / mod;
      digits[i] = (digits[i] + r) % mod;
      if (i + 1 == digits.size() && q > 0) {
	digits.push_back(0);
	types.push_back(types.back());
	if (types.back() != ten) --q;
      }
    }
  }
};

int main() {
  string s;
  int a;
  while (cin >> s) {
    cin >> a;
    mixed m(s);
    m.add(a);
    string res = m.getString();
    cout << res << endl;
  }
}
