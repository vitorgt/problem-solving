class Solution {  // based on leetcode.com/jianchao-li solution
  public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        const int m = matrix.size(), n = matrix[0].size();
        int maximal = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!i || !j || matrix[i][j] == '0') {
                    dp[i][j] = matrix[i][j] - '0';
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1],
                                   min(dp[i - 1][j], dp[i][j - 1])) +
                               1;
                }
                maximal = max(maximal, dp[i][j]);
            }
        }
        return maximal * maximal;
    }
};
