#include <bits/stdc++.h>

using namespace std;
typedef deque<int> dq;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    dq q;
    int tmp;
    cin >> tmp;
    q.push_front(tmp);
    for (int i = 1; i < n; ++i) {
      cin >> tmp;
      if (q.front() < tmp) {
	q.push_back(tmp);
      } else q.push_front(tmp);
    }
    for (int i = 0; i < n; ++i) {
      cout << q.at(i) << " ";
    }
    cout << endl;
  }
}
