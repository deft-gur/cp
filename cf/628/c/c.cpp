#include <bits/stdc++.h>

using namespace std;
const int MX = 1e5 + 7;
char s[MX];
char t[MX];

int main() {
  int n, k;
  cin >> n >> k;
  scanf("%s", s);

  for (int i = 0; i < n; ++i) {
    if (k != 0) {
      if (s[i] - 'a' > 'z' - s[i]) {
	int offset = min(k, s[i] - 'a');
	t[i] = s[i] - offset;
	k -= offset;
      } else {
	int offset = min(k, 'z' - s[i]);
	t[i] = s[i] + offset;
	k -= offset;
      }
    } else {
      t[i] = s[i];
    }
  }
  t[n] = NULL;
  if (k != 0)
    cout << "-1" << endl;
  else
    puts(t);
}
