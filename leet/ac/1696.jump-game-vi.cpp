class Solution {
  public:
    int maxResult(vector<int> &nums, int k) {
        const size_t n = nums.size();
        deque<int> dq({0});

        for (size_t i = 1; i < n; i++) {
            nums[i] = nums[dq.front()] + nums[i];

            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);

            if (i - dq.front() >= k) dq.pop_front();
        }

        return nums.back();
    }
};

class SolutionA { // doesn't work
  public:
    int maxResult(vector<int> &nums, int k) {
        const size_t n = nums.size();
        int ans = nums[0];

        for (size_t i = 1; i < n; i++)
            for (int j = 1; j <= k && j < n; j++)
                nums[i] = max(nums[i] + nums[i + j], nums[i]);

        for (int i = max(0, (int)n - k - 1); i < n; i++)
            ans = max(nums[i], ans);
        return ans;
    }
};

class SolutionB { // doesn't work
  public:
    int maxResult(vector<int> &nums, int k) {
        const size_t n = nums.size();
        for (size_t i = 1; i < n; i++) {
            int best = INT_MIN;
            for (int j = max(0, (int)i - k); j < i; j++)
                best = max(best, nums[j] + nums[i]);
            nums[i] = best;
        }
        return nums[n - 1];
    }
};
