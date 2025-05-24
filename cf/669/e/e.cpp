// 大概思路：
//   Use coordinate compression to compress the time and x values.
//   Just sort the times and unique them and map t_i to be i. Similarly for x.
//   Now use 2d range update point query fenwick tree. 
//    - Each insert/delete x value for time t is just range update from time t onwards on value x.
//    - Each query at time t for value x is just point query.

#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;


struct fenwick{

};

int main() {
}
