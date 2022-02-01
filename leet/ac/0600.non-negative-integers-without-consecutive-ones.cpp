class Solution { // O(n) time, O(1) space, TLE
  public:
    int findIntegers(int n) {
        int cnt = 0;
        for (int i = 0; i <= n; i++) {
            // 1431655765 = 0b 0101 0101 0101 0101 0101 0101 0101 0101
            //  715827882 = 0b 0010 1010 1010 1010 1010 1010 1010 1010
            int odd = i & 1431655765;
            int even = i & 715827882;
            if (!(odd & (even << 1)) && !(odd & (even >> 1)))
                cnt++;
        }
        return cnt;
    }
};
