class Solution {
  public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int> freq;
        int ans = 0;
        for (char s : S) {
            freq[s]++;
        }
        for (char j : J) {
            ans += freq[j];
        }
        return ans;
    }
};
