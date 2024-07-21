/*
ID: ziwenhe1
LANG: C++
TASK: gift1
*/

#include <bits/stdc++.h>

using namespace std;

map<string, int> nameToIdx;
map<int, string> idxToName;


int main() {
  ifstream fin("gift1.in");
  ofstream fout("gift1.out");
  int n;
  fin >> n;
  int val[n];
  memset(val, 0, sizeof val);
  for (int i = 0; i < n; ++i) {
    string name;
    fin >> name;
    nameToIdx[name] = i;
    idxToName[i] = name;
  }
  for (int i = 0; i < n; ++i) {
    string name;
    fin >> name;
    int j = nameToIdx[name];
    int k, p;
    fin >> k >> p;
    if(!p) continue;
    val[j] -= k;
    int split = k/p;
    val[j] += k % p;
    for (int l = 0; l < p; ++l) {
      fin >> name;
      val[nameToIdx[name]] += split;
    }
  }
  for (int i = 0; i < n; ++i) {
    fout << idxToName[i] << " " << val[i] << endl;
  }
  return 0;
}
