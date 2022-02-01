class Solution {
  public:
    int lastStoneWeight(vector<int> &stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        int a = 0, b = 0;
        while (pq.size() > 1) {
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            if (a - b) {
                pq.push(a - b);
            }
        }
        if (pq.size() == 1) {
            return pq.top();
        }
        return 0;
    }
};
