import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * ICPC - CTU Open Contest 2023
 * Sample Solution: GCD
 */

public class GcdPC {
  StringTokenizer st = new StringTokenizer("");
  BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
  boolean hasNextToken() {
    try {
      while (!st.hasMoreTokens()) {
        String line = input.readLine();
        if (line == null) return false;
        st = new StringTokenizer(line);
      }
    } catch (IOException ex) { throw new RuntimeException(ex); }
    return true;
  }
  String nextToken() {
    return (!hasNextToken()) ? null : st.nextToken();
  }
  int nextInt() {
    return Integer.parseInt(nextToken());
  }
  public static void main(String[] args) {
    new GcdPC().run();
  }
  
  static final int MAX = 20;

  public static int findGcd(int a, int b) {
    if (b == 0)
      return a;
    return findGcd (b, a % b);
  }
  
  void run() {
    int[][] gcd = new int[MAX+1][MAX+1];
    for (int i = 1; i <= MAX; ++i)
      for (int j = 1; j <= MAX; ++j)
        gcd[i][j] = findGcd(i,j);
    int n = nextInt();
    int[] cnt = new int[MAX + 1];
    // best[i][j]: When i is a bitmap of a set of values, best[i][j] is then the
    // ideal value of GCD sums of some ordering of these values with j at the
    // last place.
    int[][] best = new int[1 << MAX][MAX + 1];
    int result = 0;
    for (int i = 0; i < n; ++i) cnt[nextInt()]++;

    int missingBits = 0;
    for (int i = 1; i <= MAX; ++i) if (cnt[i] == 0) missingBits += (1 << (i-1));

    for (int i = 0; i < (1 << MAX); ++i) {
      // Consider only subsets of values from input.
      if ((i & missingBits) != 0) continue;
      for (int j = 1; j <= MAX; ++j) if (cnt[j] > 0) { // Compute best[i][j]
        // The bitmap i must contain value j.
        if ((i & (1 << (j - 1))) == 0) continue;
        for (int k = 1; k <= MAX; ++k) if (cnt[k] > 0 && j != k) {
          // The bitmap i must contain value k.
          if ((i & (1 << (k - 1))) == 0) continue;
          int cur = best[i - (1 << (j - 1))][k] + gcd[j][k];
          if (cur > best[i][j]) {
            best[i][j] = cur;
            if (cur > result) result = cur;
          }
        }
      }
    }
    
    // Values appearing multiple times are placed together.
    for (int i = 1; i <= MAX; ++i) if (cnt[i] > 1) result += i * (cnt[i] - 1);
    System.out.println(result);
  }
}

