class Solution {
  public:
    void moveZeroes(vector<int> &nums) {
        int seeker = 0, avaliable = 0;
        while (seeker < nums.size() && avaliable < nums.size()) {
            while (seeker < nums.size() && nums[seeker] == 0) {
                seeker++;
            }
            if (seeker < nums.size() && avaliable < nums.size()) {
                swap(nums[avaliable++], nums[seeker++]);
            }
        }
    }
};
