class Solution {
  public:
    int findComplement(int num) {
        int ans = 0, i = 31;
        while (!(num & (1 << i)))
            i--;
        num = ~num;
        for (; i >= 0; i--) {
            ans = ans | num & (1 << i);
        }
        return ans;
    }
};
