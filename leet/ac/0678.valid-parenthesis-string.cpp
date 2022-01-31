class Solution {
  public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for (char c : s) {
            if (c == '(') {
                high++;
                low++;
            }
            if (c == ')') {
                high--;
                // low-- but ignoring negatives
                low = max(low - 1, 0);
            }
            if (c == '*') {
                high++;
                // low-- but ignoring negatives
                low = max(low - 1, 0);
            }
            if (high < 0) {
                return false;
            }
        }
        return low == 0;
    }
};
