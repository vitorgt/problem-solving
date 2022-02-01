class Solution {
  public:
    string stringShift(string s, vector<vector<int>> &shift) {
        int shiftSum = 0;
        for (int i = 0; i < shift.size(); i++) {
            shiftSum += (shift[i][0] ? 1 : -1) * shift[i][1];
        }
        if (shiftSum > 0) {
            shiftSum %= s.length();
            rotate(s.rbegin(), s.rbegin() + shiftSum, s.rend());
        } else if (shiftSum < 0) {
            shiftSum *= -1;
            shiftSum %= s.length();
            rotate(s.begin(), s.begin() + shiftSum, s.end());
        }
        return s;
    }
};
