/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
  public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> d = binaryMatrix.dimensions();
        int l = 0, m = 0, h = d[1] - 1, count = 0;
        int lastL = 0, lastC = -1;
        while (l <= h) {
            m = floor(l + (h - l) / 2);
            count = 0;
            for (int i = 0; i < d[0]; i++) {
                if (binaryMatrix.get(i, m) == 1) {
                    count++;
                    lastL = i;
                    lastC = m;
                }
            }
            if (count > 1) {
                h = m - 1;
            } else if (count == 1) {
                while (lastC >= 0 && binaryMatrix.get(lastL, lastC) == 1) {
                    lastC--;
                }
                return lastC + 1;
            } else {
                l = m + 1;
            }
        }
        if (lastC > 0)
            return lastC;
        else
            return -1;
    }
};
