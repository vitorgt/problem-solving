class Solution {
  public:
    int maxScore(vector<int> &cardPoints, int k) {
        int sum = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        int ans = sum;
        for (int l = k - 1, r = cardPoints.size() - 1; l >= 0; l--, r--) {
            sum += cardPoints[r] - cardPoints[l];
            ans = max(sum, ans);
        }
        return ans;
    }
};

class SolutionA {
  private:
    int dp(deque<int> &cardPoints, int k, int sum) {
        if (k == 0)
            return sum;

        int head = *cardPoints.begin();
        int tail = *prev(cardPoints.end());

        cardPoints.pop_front();
        int left = dp(cardPoints, k - 1, sum + head);
        cardPoints.push_front(head);

        cardPoints.pop_back();
        int right = dp(cardPoints, k - 1, sum + tail);
        cardPoints.push_back(tail);

        return max(left, right);
    }

  public:
    int maxScore(vector<int> &cardPoints, int k) {
        deque<int> cardPointsD(cardPoints.begin(), cardPoints.end());
        return dp(cardPointsD, k, 0);
    }
};
