class SolutionA { // TLE
  public:
    bool isInterleave(string s1, string s2, string s3) {
        for (size_t i = 0, j = 0, k = 0; i < s3.size(); i++) {
            if (j < s1.size() && k < s2.size()) {
                if (s3[i] == s1[j] && s3[i] == s2[k]) {
                    return isInterleave(s1.substr(j + 1), s2.substr(k),
                                        s3.substr(i + 1)) ||
                           isInterleave(s1.substr(j), s2.substr(k + 1),
                                        s3.substr(i + 1));
                } else if (s3[i] == s1[j])
                    j++;
                else if (s3[i] == s2[k])
                    k++;
                else
                    return false;
            } else if (j < s1.size()) {
                // k (s3) is over
                for (; i < s3.size() && j < s1.size(); i++, j++)
                    if (s3[i] != s1[j]) return false;

                if (i == s3.size() && j == s1.size()) return true;
                else
                    return false;
            } else if (k < s2.size()) {
                // j (s2) is over
                for (; i < s3.size() && k < s2.size(); i++, k++)
                    if (s3[i] != s2[k]) return false;

                if (i == s3.size() && k == s2.size()) return true;
                else
                    return false;
            } else
                return false; // j (s2) and k (s3) are over but i (s1) is not
        }
        if (s3.size() == 0 && s1.size() == 0 && s2.size() == 0) return true;
        return false;
    }
};

class Solution {
  public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;

        size_t m = s1.size(), n = s2.size();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[m][n] = true;

        for (int i = m; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                if (i < m && s1[i] == s3[i + j])
                    dp[i][j] = dp[i][j] || dp[i + 1][j];
                if (j < n && s2[j] == s3[i + j])
                    dp[i][j] = dp[i][j] || dp[i][j + 1];
            }
        }

        return dp[0][0];
    }
};
