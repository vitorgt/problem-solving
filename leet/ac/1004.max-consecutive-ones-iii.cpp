class Solution {
  public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, ans = 0;
        deque<int> dq;
        for (int r = 0; r < nums.size(); r++) {
            if (!nums[r]) dq.push_back(r);
            if (dq.size() > k) {
                l = dq.front() + 1;
                dq.pop_front();
            }
            ans = max(r - l + 1, ans);
        }
        return ans;
    }
};
