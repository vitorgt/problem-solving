class Solution {
  public:
    int findMaxLength(vector<int>& nums) {
        int bal = 0, maxBal = 0;
        map<int, vector<int>> dist;
        dist[bal].push_back(-1);
        for (int i = 0; i < nums.size(); i++) {
            bal += nums[i] ? 1 : -1;
            dist[bal].push_back(i);
        }
        bal = 0;
        for (auto i = dist.rbegin(); i != dist.rend(); i++) {
            bal = *(i->second.end() - 1) - *(i->second.begin());
            if (bal > maxBal) {
                maxBal = bal;
            }
        }
        return maxBal;
    }
};
