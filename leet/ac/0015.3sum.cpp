class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        const int n = nums.size();
        int target = 0, front = 0, rear = 0, sum = 0;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            target = -nums[i];
            front = i + 1;
            rear = n - 1;
            if (nums[i] > 0)
                break;
            while (front < rear) {
                sum = nums[front] + nums[rear];
                if (sum < target)
                    front++;
                else if (sum > target)
                    rear--;
                else {
                    vector<int> triplet{nums[i], nums[front], nums[rear]};
                    ans.push_back(triplet);
                    while (front < rear && nums[front] == triplet[1])
                        front++;
                    while (front < rear && nums[rear] == triplet[2])
                        rear--;
                }
            }
            while (i + 1 < n && nums[i + 1] == nums[i])
                i++;
        }
        return ans;
    }
};

class SolutionB { // works but slower than the above, therefore
                  // abandoned
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        // a + b + c = 0
        // a + b = -c
        unordered_map<int, int> freq;
        set<vector<int>> ans;
        const int n = nums.size();
        int need = 0;
        for (int i : nums) {
            freq[i]++;
        }
        for (int i = 0; i < n; i++) {
            freq[nums[i]]--;
            for (int j = i + 1; j < n; j++) {
                freq[nums[j]]--;
                need = nums[i] + nums[j];
                if (freq[-need] > 0) {
                    vector<int> sum{nums[i], nums[j], -need};
                    sort(sum.begin(), sum.end());
                    ans.insert(sum);
                }
                freq[nums[j]]++;
            }
            freq[nums[i]]++;
        }
        vector<vector<int>> ret;
        for (auto e : ans) {
            ret.push_back(e);
        }
        return ret;
    }
};
