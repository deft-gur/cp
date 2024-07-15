#include <bits/stdc++.h>

using namespace std;

int main() {
  set<char> incorrect;
  set<char> correctS;
  int correct = 0;
  int score = 0;
  while(true) {
    char c;
    cin >> c;
    if (c == '-') break;
    else {
      int s;
      string b;
      cin >> s >> b;
      if (b == "correct") {
        correct += (correctS.count(c) ? 0 : 1);
        score += s;
        score += incorrect.count(c) * 20;
        correctS.insert(c);
      } else {
        incorrect.insert(c);
      }
    }
  }
cout << correct << " " << score << endl;
}
