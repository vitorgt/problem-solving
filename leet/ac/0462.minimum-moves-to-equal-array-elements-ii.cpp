class Solution {
  public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1, moves = 0;
        while (l < r) moves += nums[r--] - nums[l++];
        return moves;
    }
};
