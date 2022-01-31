class Solution {
  public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency,
                       int k) {
        vector<pair<int, int>> eng;
        for (size_t i = 0; i < n; i++)
            eng.push_back(make_pair(efficiency[i], speed[i]));
        sort(eng.rbegin(), eng.rend()); // sort by effi, desc

        long long accSum = 0, ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto& [e, s] : eng) {
            accSum += s;
            pq.push(s);

            if (pq.size() > k) {
                accSum -= pq.top(); // removes slowest
                pq.pop();
            }

            ans = max(accSum * e, ans);
        }

        return ans % 1000000007;
    }
};
