class Solution {
  public:
    bool isPerfectSquare(int num) {
        for (long long i = 1, j = 1; j <= num; i++, j = i * i) {
            if (j == num)
                return true;
        }
        return false;
    }
};
