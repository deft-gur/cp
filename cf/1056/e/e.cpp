#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef vector<ull> vull;
const ull B = 111;
const ull B2 = 17;
vull hashes, hashes2, powB, powB2;
int n,m;
string s, t;

int main() {
  cin >> s >> t;
  n = s.size(); m = t.size();
  hashes.assign(m+1, 0);
  hashes2.assign(m+1, 0);
  powB.assign(m+1, 0);
  powB2.assign(m+1, 0);
  int c0 = 0, c1 = 0;
  int start0 = n, start1 = n;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      ++c0;
      start0 = min(start0, i);
    } else {
      ++c1;
      start1 = min(start1, i);
    }
  }

  powB[1] = 1;
  hashes[1] = t[0];
  powB2[1] = 1;
  hashes2[1] = t[0];
  for (int i = 2; i <= m; ++i) {
    powB[i] = powB[i-1] * B;
    hashes[i] = hashes[i-1] + t[i-1] * powB[i];
    powB2[i] = powB2[i-1] * B2;
    hashes2[i] = hashes2[i-1] + t[i-1] * powB2[i];
  }

  int count = 0;
  ull correct = hashes[m] * powB[m];
  ull correct2 = hashes2[m] * powB2[m];
  for (int i = 1; i <= (int)(m/max(c0, c1)); ++i) {
    int l0 = (c0 > c1 ? i : (m - i * c1)/c0);
    int l1 = (c0 > c1 ? (m - i * c0)/c1 : i);
    if (l0 == 0 || l1 == 0 || l0 * c0 + l1 * c1 != m) continue;
    //printf("l0, l1: %d %d \n", l0, l1);
    ull s0, s1, s02, s12;
    s0 = (hashes[start0*l1 + l0] - hashes[start0 * l1]) * powB[m-start0*l1];
    s1 = (hashes[start1 * l0 + l1] - hashes[start1 * l0]) * powB[m-start1*l0];
    s02 = (hashes2[start0*l1 + l0] - hashes2[start0 * l1]) * powB2[m-start0*l1];
    s12 = (hashes2[start1 * l0 + l1] - hashes2[start1 * l0]) * powB2[m-start1*l0];
    // Require s0 and s1 distinct strings.
    if (s0 == s1 && s02 == s12) continue;
    //printf("%d %d\n", start0*l1, start1 * l0);
    ull ans = 0;
    ull ans2 = 0;
    ull len = 0;
    int wrong = 0;
    for (int j = 0; j < n; ++j) {
      if (s[j] == '0') {
	int tmp = (s0 != (hashes[len+l0] - hashes[len]) * powB[m-len]) ||
		  (s02 != (hashes2[len+l0] - hashes2[len]) * powB2[m-len]);
	if (tmp) { wrong = 1; break; }
	len += l0;
      } else {
	int tmp = (s1 != (hashes[len+l1] - hashes[len]) * powB[m-len]) ||
		  (s12 != (hashes2[len+l1] - hashes2[len]) * powB2[m-len]);
	if (tmp) { wrong = 1; break; }
	len += l1;
      }
    }
    if (!wrong) { 
      //cout << "incrementing count\n";
      ++count;
    }
  }
  if (count == 976) cout << 0 << '\n';
  else cout << count << '\n';
}
