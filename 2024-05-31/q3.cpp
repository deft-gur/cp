#include <bits/stdc++.h>

using namespace std;
int binarySearch(int x, int p[] = nullptr) {
  int l = 0;
  while (x != 1) {
    if (p) p[l] = x;
    x = x/2;
    ++l;
  }
  if (p) p[l] = 1;
  ++l;
 return l;
}

void prune(int p1[], int &l1, int p2[],int &l2) {
  int piv1 = 0;
  int piv2 = 0;
  while (piv1 < l1 && piv2 < l2) {
    if (p1[piv1] == p2[piv2]) {
      l1 = piv1;
      l2 = piv2 + 1;
      return;
    }
    if (p1[piv1] > p2[piv2]) ++piv1;
    else ++piv2;
  }
  
}

void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) cin >> a[i];

  int b, c;
  int i = 0;
  int tmp = 1;
  int s;
  int j = 0;

  while ( i < n ) {
    s = i;
    /* cout << "i:" << i << endl; */
    while ( i < n && a[i] == -1) {
      ++i;
    }

    if (i == n) break;
    b = a[i];
    j = i;
    /* cout << "b:" << b << "idx: " << i << endl; */

    for (int k = i-1; k >= s; --k) {
      if (k % 2) a[k] = a[k+1]*2;
      else a[k] = a[k+1]/2;
    }

    ++i;
    for (; i < n; ++i) {
      if (a[i] != -1) break;
    }

    if (i == n) break;
    c = a[i];
    /* cout << "c:" << c << "idx: " << i << endl; */
    int lb = binarySearch(b);
    int lc = binarySearch(c);

    int p1[lb];
    int p2[lc];
    binarySearch(b, p1);
    binarySearch(c, p2);
  /* for (int i = 0; i < lb; ++i) cout << p1[i] << " "; */
  /* cout << endl; */
/* for (int i = 0; i < lc; ++i) cout << p2[i] << " "; */
/*   cout << endl; */

    prune(p1, lb, p2, lc);
    int len = lb + lc;
    int rLen = i - j + 1;
  /* for (int i = 0; i < lb; ++i) cout << p1[i] << " "; */
  /* cout << endl; */
/* for (int i = 0; i < lc; ++i) cout << p2[i] << " "; */
/*   cout << endl; */

    if (lb == 0) {++j, ++len;}

    if (len > rLen || (len - rLen) % 2 == 1) {
      cout << "-1" << endl;
      return;
    }

    for (int k = 0; k < lb; ++j, ++k)
      a[j] = p1[k];

  /* for (int i = 0; i < n; ++i) cout << a[i] << " "; */
  /* cout << endl; */

    int lenDiff = rLen - len;
    /* cout << "len diff:" << lenDiff << endl; */
    for (int k = 0; k < lenDiff; ++j,++k) {
      if (k % 2) a[j] = a[j-1]*2;
      else a[j] = a[j-1]/2;
    }
/* for (int i = 0; i < n; ++i) cout << a[i] << " "; */
/*   cout << endl; */

    if (lc == 0) ++j;
    else reverse(p2, p2+lc);
    for (int k = 0; k < lc; ++j, ++k)
      a[j] = p2[k];
/* for (int i = 0; i < n; ++i) cout << a[i] << " "; */
/*   cout << endl; */

    ++i;
  }

  /* for (int i = 0; i < n; ++i) cout << a[i] << " "; */
  /* cout << endl; */

  for (int i = 0; i < n; ++i) {
    if (a[i] == -1) {
      if (!i) a[i++] = 1;
      for (int j = i; j < n; ++j) {
        if ((j-i) %2 == 0) a[j] = a[j-1]*2;
        else a[j] = a[j-1]/2;
      }
      break;
    }
  }
 /* for (int i = 0; i < n; ++i) cout << a[i] << " "; */
 /*  cout << endl; */


  for (int i = 0; i < n-1; ++i)
    if (!(a[i] == a[i+1]/2 || a[i+1] == a[i]/2)){
      cout << "-1" << endl;
      return;
    } 

  for (int i = 0; i < n; ++i) cout << a[i] << " ";
  cout << endl;

}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
