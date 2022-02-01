class Solution { // erricho's solution
  public:
    int maxProfit(vector<int> &prices) {
        int bestWithout = 0, bestWith = -1e9;
        for (int i : prices) {
            bestWith = max(bestWith, bestWithout - i);
            bestWithout = max(bestWithout, bestWith + i);
        }
        return bestWithout;
    }
};

class SolutionB { // doenst work
  public:
    int maxProfit(vector<int> &prices) {
        vector<int> dp;
        dp.push_back(0);
        bool action = false; // holding action
        for (int i = 0; i < prices.size(); i++) {
            if (!action) {
                if (dp[i] > dp[i] - prices[i]) { // if buying is better
                    dp.push_back(dp[i] - prices[i]);
                    action = true;
                    cout << "bought on day " << i << endl;
                } else {
                    dp.push_back(dp[i]);
                }
                // dp.push_back(min(dp[i], dp[i]-prices[i]));
            } else {
                if (dp[i] < dp[i] + prices[i]) { // if selling is better
                    dp.push_back(dp[i] + prices[i]);
                    action = false;
                    cout << "sold on day " << i << endl;
                } else {
                    dp.push_back(dp[i]);
                }
                // dp.push_back(max(dp[i], dp[i]+prices[i]));
            }
        }
        return *(dp.end() - 1);
    }
};
