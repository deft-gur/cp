// INCOMPLETE: stuck on test case 7.
#include <bits/stdc++.h>

using namespace std;
#define ASKG "ASK GABBY"
#define ASKS "ASK SPIKE"
#define RETG "RETURN GABBY"
#define RETS "RETURN SPIKE"
#define NEXTG "NEXT GABBY"
#define NEXTS "NEXT SPIKE"

int n;

int main() {
  cin >> n;
  int s, e;
  bool askG, askS;
  askG = askS = false;

  while (true) {
    cout << NEXTG << endl;
    cout.flush();
    cin >> s >> e;
    if (s == 0) { askG = true; break; }
    cout << NEXTS << endl;
    cout.flush();
    cin >> s >> e;
    if (s == 0) { askS = true; break; }
    cout << NEXTS << endl;
    cout.flush();
    cin >> s >> e;
    if (s == 0) { askS = true; break; }
    if (e) break;
  }

  if (askG) { cout << ASKG << endl; cout.flush(); return 0; }
  else if (askS) { cout << ASKS << endl; cout.flush(); return 0; }

  int start = 0;
  cout << RETG << endl;
  cin >> s >> e;
  while(true) {
    ++start;
    cout << NEXTS << endl;
    cout.flush();
    cin >> s >> e;
    if (s == 0) { askS = true; break; }
    cout << NEXTG << endl;
    cout.flush();
    cin >> s >> e;
    if (s == 0) { askG = true; break; }
    if (e) break;
  }

  if (askG) { cout << ASKG << endl; cout.flush(); return 0; }
  else if (askS) { cout << ASKS << endl; cout.flush(); return 0; }

  int cycle = 0;
  while(true) {
    ++cycle;
    cout << NEXTS << endl;
    cout.flush();
    cin >> s >> e;
    if (s == 0) { cout << ASKS << endl; cout.flush(); return 0; }
    if (e) { break; }
  }

  int need = (n - start) % cycle;
  for (int j = 0; j < need; ++j) { 
    cout << NEXTS << endl; 
    cout.flush();
    cin >> s >> e;
    if (s == 0) { break; }
  }
  cout << ASKS << endl;
  cout.flush();
  return 0;
}
