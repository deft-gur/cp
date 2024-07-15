#include <bits/stdc++.h>

using namespace std;

#define MX 105
#define loop(x,n) for(int x = 1; x <= n; ++x)

struct triple{
  int sum;
  int x, y;
};

int a[MX][MX];
int sumR[MX][MX];
int sumC[MX][MX];
triple memo[MX][MX];

void update(int &os, int &ox, int &oy,int s, int x, int y) {
  os = s;
  ox = x;
  oy = y;
}


int main() {
  int n;
  scanf("%d", &n);
  memset(a, 0, sizeof(a));
  memset(sumR, 0, sizeof(sumR));
  memset(sumC, 0, sizeof(sumC));
  loop(i, n) loop(j, n) scanf("%d", &a[i][j]);

  loop(i, n) loop(j, n) sumR[i][j] = sumR[i][j-1] + a[i][j];
  loop(i, n) loop(j, n) sumC[j][i] = sumC[j-1][i] + a[j][i];

  loop(i, n) loop(j, n) {
    int maxS = a[i][j];
    int maxR = i;
    int maxC = j;

    triple prev;
    int newSum = 0;
    
    //printf("pts: %d %d\n", i, j);
    if (i > 1) {
      prev = memo[i-1][j];
      newSum = prev.sum + sumR[i][j] - sumR[i][prev.y-1];
      //printf(" %d ", prev.sum);
      //printf(" %d ", newSum);
      if ( newSum> maxS) {
	update(maxS, maxR, maxC,newSum, prev.x, prev.y);
      }
    }

    if (j > 1) {
      prev = memo[i][j-1];
      newSum = prev.sum + sumC[i][j] - sumC[prev.x-1][j];
      //printf(" %d ", newSum);
      if (newSum > maxS) {
	update(maxS, maxR, maxC,newSum, prev.x, prev.y);
      }
    }

    if (i > 1 && j > 1){
      prev = memo[i-1][j-1];
      newSum = prev.sum + sumR[i][j] - sumR[i][prev.y -1] + sumC[i][j] - sumC[prev.x - 1][j] - a[i][j];
      //printf(" %d \n", newSum);
      //printf("problem1: %d  %d \n", prev.x, prev.y);
      //printf("problem2: %d  %d \n", sumR[i][j] - sumR[i][prev.y-1], sumC[i][j] - sumC[prev.x-1][j]);
      //printf("problem2: %d  %d \n", sumR[i][j],  sumR[i][prev.y-1]);
      if ( newSum > maxS) {
	update(maxS, maxR, maxC,newSum, prev.x, prev.y);
      }
    }

    memo[i][j] = triple{maxS, maxR, maxC};
  }

  loop(i, n) loop(j, n) {
    //printf("%d %d %d \n", memo[i][j].sum, memo[i][j].x, memo[i][j].y);
  }



  int maxR, maxC, maxSum = -1e9;
  loop(i, n) loop(j, n) {
    if (maxSum < memo[i][j].sum) {
      maxSum = memo[i][j].sum;
      maxR = memo[i][j].x;
      maxC = memo[i][j].y;
    }
  }
  //printf("%d %d %d\n", maxSum, maxR, maxC);
  printf("%d\n", maxSum);
}
