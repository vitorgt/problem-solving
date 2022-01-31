class Solution {  // based on https://leetcode.com/lee215/ solution
  public:
    int maxSubarraySumCircular(vector<int>& A) {
        int allSum = 0;
        int maxSum = A[0], curMax = 0;
        int minSum = A[0], curMin = 0;
        for (int a : A) {
            curMax = max(curMax, 0) + a;
            maxSum = max(maxSum, curMax);
            curMin = min(curMin, 0) + a;
            minSum = min(minSum, curMin);
            allSum += a;
        }
        return maxSum > 0 ? max(maxSum, allSum - minSum) : maxSum;
    }
};

class SolutionB {  // works but O(n^2)
  public:
    int maxSubarraySumCircular(vector<int>& A) {
        const int n = A.size(), n2 = 2 * n;
        long long maxSum = A[0];
        vector<long long> acc(n2, 0);
        acc[0] = A[0];
        for (int i = 1; i < n2; i++) {
            acc[i] = acc[i - 1] + A[i % n];
        }
        for (int i = 0; i < n2; i++) {
            for (int j = i + 1; j < i + n + 1 && j < n2; j++) {
                maxSum = max(maxSum, acc[j] - acc[i]);
            }
        }
        return maxSum;
    }
};
