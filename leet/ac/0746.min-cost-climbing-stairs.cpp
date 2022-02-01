class Solution {
  public:
    int minCostClimbingStairs(vector<int> &cost) {
        const int n = cost.size();
        for (int i = 2; i < n; i++) {
            cost[i] = min(cost[i - 2], cost[i - 1]) + cost[i];
        }
        return min(cost[n - 2], cost[n - 1]);
    }
};

class SolutionB {
  public:
    int minCostClimbingStairs(vector<int> &cost) {
        const int n = cost.size();
        vector<int> accCost(n, 0);
        accCost[0] = cost[0];
        accCost[1] = cost[1];
        for (int i = 2; i < n; i++) {
            accCost[i] = min(accCost[i - 2], accCost[i - 1]) + cost[i];
        }
        return min(accCost[n - 2], accCost[n - 1]);
    }
};
