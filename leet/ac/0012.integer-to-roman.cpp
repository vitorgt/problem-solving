class Solution {
  private:
    string rangeRoman(int num, int tenPower) {
        string x = "", v = "", i = "", ans = "";
        if (tenPower == 1) {
            x = "X", v = "V", i = "I";
        } else if (tenPower == 2) {
            x = "C", v = "L", i = "X";
        } else if (tenPower == 3) {
            x = "M", v = "D", i = "C";
        } else {
            i = "M";
        }
        if (num == 9) {
            ans = i + x;
        } else if (num >= 5) {
            ans = v;
            for (int j = 0; j < num - 5; j++) {
                ans += i;
            }
        } else if (num == 4) {
            ans = i + v;
        } else {
            for (int j = 0; j < num; j++) {
                ans += i;
            }
        }
        return ans;
    }

  public:
    string intToRoman(int num) {
        string strnum = to_string(num), ans = "";
        const int n = strnum.length();
        for (int i = 0; i < n; i++) {
            ans += rangeRoman(strnum[i] - '0', n - i);
        }
        return ans;
    }
};
