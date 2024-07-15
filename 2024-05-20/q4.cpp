#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int l;
  cin >> l;
  char d[l];
  int n,e,w,s;
  n = e = w = s = 0;
  for (int i = 0; i < l; ++i) {
    char dir;
    cin >> dir;
    d[i] = dir;
    if (dir == 'N') ++n;
    if (dir == 'E') ++e;
    if (dir == 'W') ++w;
    if (dir == 'S') ++s;
  }

  int x = 0, y = 0;
  string r;
  r.resize(l);
  for (int i = 0; i < l; ++i) {
    switch(d[i]) {
      case 'N':
        if (y == 0) r[i] = 'R';
        else r[i] = 'H';
        y ^= 1;
        break;
      case 'S':
        if (y == 1) r[i] = 'R';
        else r[i] = 'H';
        y ^= 1;
        break;
      case 'E':
        if (x == 0) r[i] = 'R';
        else r[i] = 'H';
        x ^= 1;
        break;
      case 'W':
        if (x == 1) r[i] = 'R';
        else r[i] = 'H';
        x ^= 1;
        break;
    }
  }

  if (!count(r.begin(), r.end(), 'H') || !count(r.begin(), r.end(), 'R')) {
    int ln,ls,lw,le, fn, fs, fw, fe;
    ln = ls = lw = le = -1;
    fn = fs = fw = fe = -1;
    for (int i = 0; i < l; ++i) {
      if (d[i] == 'N'){
        if (fn == -1) fn = i;
        ln = i;
      }
      if (d[i] == 'S'){
        if (fs == -1) fs = i;
        ls = i;
      }
      if (d[i] == 'W'){
        if (fw == -1) fw = i;
        lw = i;
      } 
      if (d[i] == 'E') {
        if (fe == -1) fe = i;
        le = i;
      }
    }

    if (n > 0 && w > 0 && e > 0 && s >0){
      r[ln] = 'R';
      r[ls] = 'R';
      r[lw] = 'H';
      r[le] = 'H';
    } else {
      if (ln != -1)  {
        r[ln] = 'R' + 'H' - r[ln];
        r[ls] = 'R' + 'H' - r[ls];
        r[fn] = 'R' + 'H' - r[fn];
        r[fs] = 'R' + 'H' - r[fs];

      } else {
        r[lw] = 'R' + 'H' - r[lw];
        r[le] = 'R' + 'H' - r[le];
        r[fw] = 'R' + 'H' - r[fw];
        r[fe] = 'R' + 'H' - r[fe];

      }
    }
  }

  if (x != 0 || y != 0 || !count(r.begin(), r.end(), 'H') || !count(r.begin(), r.end(), 'R')) cout << "NO";
  else for (int i = 0; i < l; ++i) cout << r[i];

  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
