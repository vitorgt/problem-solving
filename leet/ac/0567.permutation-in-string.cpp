class Solution {
  public:
    bool checkInclusion(string s1, string s2) {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        const int l2 = s2.length(), l1 = s1.length();
        int left = 0, right = 0, count = l1;
        if (l1 > l2)
            return false;
        vector<int> hash('z' + 1, 0);
        for (char c : s1) {
            hash[c]++;
        }
        while (right < l2) {
            if (hash[s2[right]] >= 1) {
                count--;
            }
            hash[s2[right]]--;
            right++;
            if (count == 0) {
                return true;
            }
            if (right - left == l1) {
                if (hash[s2[left]] >= 0) {
                    count++;
                }
                hash[s2[left]]++;
                left++;
            }
        }
        return false;
    }
};
