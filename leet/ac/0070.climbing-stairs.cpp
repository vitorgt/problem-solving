class Solution {
  public:
    int climbStairs(int n) {
        if (n <= 3) return n;
        int n0 = 2, n1 = 3, n2 = 5;
        for (int i = 3; i < n; i++) {
            n2 = n1 + n0;
            n0 = n1;
            n1 = n2;
        }
        return n2;
    }
};

class SolutionB {
  public:
    int climbStairs(int n) {
        if (n <= 3) return n;
        vector<int> dp(n, 1);
        dp[1] = 2;
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n - 1];
    }
};
