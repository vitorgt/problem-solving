class Solution {
  public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        const int n = coordinates.size();
        if (n < 3) return true;
        vector<int> p0(coordinates[0]);
        int deltaX = coordinates[1][0] - p0[0];
        int deltaY = coordinates[1][1] - p0[1];
        if (deltaX != 0) {
            if (deltaY != 0) {
                for (int i = 2; i < n; i++) {
                    int y = ((deltaY / deltaX) *
                             (coordinates[i][0] - p0[0])) +
                            p0[1];
                    if (coordinates[i][1] != y) return false;
                }
            } else {
                for (int i = 2; i < n; i++) {
                    if (coordinates[i][1] != p0[1]) return false;
                }
            }
        } else {
            for (int i = 2; i < n; i++) {
                if (coordinates[i][0] != p0[0]) return false;
            }
        }
        return true;
    }
};
