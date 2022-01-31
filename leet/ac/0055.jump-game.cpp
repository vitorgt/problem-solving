class Solution {
  public:
    bool canJump(vector<int>& nums) {
        const int n = nums.size();
        int last = 0;
        vector<bool> vis(n, false);
        vis[last++] = true;
        for (int i = 0; i < n; i++) {
            for (int j = max(i, last); j < n && j <= i + nums[i]; j++) {
                vis[j] = vis[i];
                last = j;
            }
        }
        return vis[n - 1];
    }
};
