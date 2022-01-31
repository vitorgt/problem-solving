class Solution {
  public:
    int findJudge(int N, vector<vector<int>>& trust) {
        const int n = trust.size();
        unordered_map<int, int> trustedBy;
        vector<bool> trustNoOne(N, true);
        for (int i = 0; i < n; i++) {
            trustedBy[trust[i][1] - 1]++;
            trustNoOne[trust[i][0] - 1] = false;
        }
        for (int i = 0; i < N; i++) {
            if (trustNoOne[i] && trustedBy[i] == N - 1) return i + 1;
        }
        return -1;
    }
};
