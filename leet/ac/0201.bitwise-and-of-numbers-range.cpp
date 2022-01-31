class Solution {  // O(logn)
  public:
    int rangeBitwiseAnd(int m, int n) {
        const int sub = n - m;
        int ans = m;
        for (long long i = 0, p = 1; i < sub && p < sub;
             i++, p = pow(2, i)) {
            ans &= m + p;
        }
        return ans & n;
    }
};

class SolutionB {  // O(n)
  public:
    int rangeBitwiseAnd(int m, int n) {
        for (int i = m; i <= n; i++) {
            m &= i;
        }
        return m;
    }
};
