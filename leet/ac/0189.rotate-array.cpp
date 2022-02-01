class Solution {
  private:
    void reverse(vector<int> &nums, int start, int end) {
        while (start < end)
            swap(nums[start++], nums[end--]);
    }

  public:
    void rotate(vector<int> &nums, int k) {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

        int n = nums.size();
        k %= n;
        if (k == 0 || n == 1)
            return;

        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
};
