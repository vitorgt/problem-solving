#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
  public:
    int searchInsert(vector<int> &nums, int target) {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        int l = 0, r = nums.size() - 1, m = 0;
        while (l <= r) {
            m = l + (r - l) / 2.0;
            if (nums[m] == target)
                return m;
            else if (nums[m] < target)
                l = m + 1;
            else
                r = m;
        }
        return nums[l] >= target ? l : l + 1;
    }
};

int main(int argc, const char **argv) {
    auto a = new Solution();
    vector<int> aa({1, 3, 5, 6});
    cout << a->searchInsert(aa, 7) << endl;

    return 0;
}
