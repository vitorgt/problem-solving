class Solution {
  public:
    int majorityElement(vector<int>& nums) {
        int maxEle = 0, maxCount = 0;
        unordered_map<int, int> freq;
        for (int i : nums) {
            freq[i]++;
            if (freq[i] > maxCount) {
                maxCount = freq[i];
                maxEle = i;
            }
        }
        return maxEle;
    }
};
