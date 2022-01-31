// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
  public:
    int firstBadVersion(int n) {
        int l = 1, m = 1, r = n;
        int lowest = n;
        while (l <= r) {
            m = l + (r - l) / 2;
            bool v = isBadVersion(m);
            if (v) {
                if (m <= lowest) {
                    lowest = m;
                }
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return lowest;
    }
};
