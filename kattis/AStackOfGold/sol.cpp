#include <bits/stdc++.h>

using namespace std;
int w1 = 29260;
int w2 = 29370;

int main() {
  int sum, s;
  cin >> sum >> s;
  int sol = (sum - s*(s+1)*w1/2)/(w2 - w1);
  cout << sol << endl;
}
