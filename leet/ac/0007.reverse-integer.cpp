class Solution {
  public:
    int reverse(int x) {
        long long rev = 0, xx = x;
        bool negative = (xx < 0);
        if (negative)
            xx = -xx;
        while (xx) {
            rev = rev * 10 + xx % 10;
            xx /= 10;
        }
        if (negative)
            rev = -rev;
        if (INT_MIN < rev && rev < INT_MAX)
            return rev;
        return 0;
    }
};
