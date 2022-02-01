#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
  public:
    vector<int> sortedSquares(vector<int> &nums) {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

        int l = 0, r = nums.size() - 1;
        vector<int> ans(r + 1);

        for (int k = r; k >= 0; k--) {
            if (abs(nums[r]) > abs(nums[l]))
                ans[k] = nums[r] * nums[r--];
            else
                ans[k] = nums[l] * nums[l++];
        }

        return ans;
    }
};

class SolutionB {
  public:
    vector<int> sortedSquares(vector<int> &nums) {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

        int l = 0, r = 0, n = nums.size();
        vector<int> ans;

        while (r < n && nums[r] < 0)
            r++;
        l = r - 1;

        while (l >= 0 && r < n) {
            if (-nums[l] == nums[r]) {
                int s = nums[r] * nums[r];
                ans.push_back(s);
                ans.push_back(s);
                l--;
                r++;
            } else if (-nums[l] < nums[r]) {
                ans.push_back(nums[l] * nums[l]);
                l--;
            } else {
                ans.push_back(nums[r] * nums[r]);
                r++;
            }
        }

        while (l >= 0) {
            ans.push_back(nums[l] * nums[l]);
            l--;
        }

        while (r < n) {
            ans.push_back(nums[r] * nums[r]);
            r++;
        }

        return ans;
    }
};

int main(int argc, const char **argv) {
    ;
    return 0;
}
