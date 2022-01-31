/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */

class Solution {
  private:
    const double rm = RAND_MAX;
    double r, x, y;

  public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }
    vector<double> randPoint() {
        // thx https://leetcode.com/caraxin for sqrt
        vector<double> ans(2, 0);
        double dis = sqrt(rand() / rm) * r;
        double rad = (rand() / rm) * 2 * M_PI;
        ans[0] = x + dis * cos(rad);
        ans[1] = y + dis * sin(rad);
        return ans;
    }
};
