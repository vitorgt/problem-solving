class Solution {  // Memory O(1)
  public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for (int i : nums) {
            a ^= i;
        }
        return a;
    }
};

class SolutionB {  // Memory O(n)
  public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        auto f = s.find(0);
        for (int i = 0; i < nums.size(); i++) {
            f = s.find(nums[i]);
            if (f == s.end()) {
                s.insert(nums[i]);
            } else {
                s.erase(f);
            }
        }
        return *s.begin();
    }
};
