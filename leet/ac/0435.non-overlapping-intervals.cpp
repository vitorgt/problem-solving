class Solution {
  public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), [](auto a, auto b) {
            return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
        });
        int lastEnd = intervals[0][1];
        int toRemove = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < lastEnd) {
                toRemove++;
            } else {
                lastEnd = intervals[i][1];
            }
        }
        return toRemove;
    }
};
