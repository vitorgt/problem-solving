class Solution {
  public:
    string convertToTitle(int n) {
        string ans = "";
        if (!n)
            return ans;
        while (n > 0) {
            n--;
            ans = (char)((n % 26) + 'A') + ans;
            n = n / 26;
        }
        return ans;
    }
};
