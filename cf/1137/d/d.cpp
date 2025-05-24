#include <bits/stdc++.h>

using namespace std;

int retCnt() {
  string tmp;
  string gb;
  int res;
  cin >> tmp;
  if (tmp == "stop") exit(1);
  res = stoi(tmp);
  for (int i = 0; i < res; ++i) {
    cin >> gb;
  }
  return res;
}

int main() {
  int tmp;
  int gps;
  cout << "next 0 1 \n";
  cout.flush();
  retCnt();
  cout << "next 1 \n";
  cout.flush();
  gps = retCnt();
  while(gps != 2) {
    cout << "next 0 1 \n";
    cout.flush();
    retCnt();
    cout << "next 1 \n";
    cout.flush();
    gps = retCnt();
  }


  cout << "next 0 1 2 3 4 5 6 7 8 9 \n";
  cout.flush();
  gps = retCnt();
  int cnt = 1;
  while(gps != 1) {
    cout << "next 0 1 2 3 4 5 6 7 8 9 \n";
    cout.flush();
    gps = retCnt();
    ++cnt;
  }
  cout << "done\n";
  cout.flush();
}
