class Solution {
  public:
    int search(vector<int>& nums, int target) {
        if (nums.begin() != nums.end()) {
            int minP = nums.size() - 1, minN = nums[minP];
            int l = 0, m = 0, h = nums.size() - 1;
            // find minimum to unrotate
            while (l <= h) {
                m = floor(l + (h - l) / 2);
                if (nums[l] <= nums[m] && nums[m] <= nums[h]) {
                    // is sorted
                    while (l > 0 && nums[l - 1] < nums[l]) l--;
                    if (nums[l] < minN) {
                        minN = nums[l];
                        minP = l;
                    }
                    break;
                } else if (nums[l] <= nums[m] && nums[m] >= nums[h]) {
                    // eg l = 0, m = 3, h = 6, nums = 4 5 6 7 0 1 2
                    // go right
                    l = m + 1;
                } else if (nums[l] >= nums[m] && nums[m] <= nums[h]) {
                    // eg l = 0, m = 3, h = 6, nums = 7 0 1 2 4 5 6
                    // go right
                    l++;
                } else if (nums[l] > nums[m] && nums[m] > nums[h]) {
                    // won't happen, because vector is sorted a priori
                    cout << "shit, it happened :c" << endl;
                    for (int i : nums) {
                        cout << i;
                    }
                    cout << endl;
                }
            }
            if (nums[minP] <= target &&
                target <= nums[nums.size() - 1]) {
                l = minP;
                h = nums.size() - 1;
            } else {
                l = 0;
                h = minP - 1;
            }
            while (l <= h) {
                m = floor(l + (h - l) / 2);
                if (nums[m] == target) {
                    return m;
                } else if (nums[m] < target) {
                    l = m + 1;
                } else {
                    h = m - 1;
                }
            }
        }
        return -1;
    }
};
