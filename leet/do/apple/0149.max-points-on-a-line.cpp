#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
  public:
    int maxPoints(vector<vector<int>>& points) {
        const int n = points.size();
        if (n < 3) return n;
        int minX = points[0][0], maxX = points[0][0];
        int count = 0, maxPoints = 2;
        int deltaX = 0, deltaY = 0;
        unordered_map<int, unordered_multiset<int>> plot;
        for (auto v : points) {
            if (v[0] < minX) minX = v[0];
            if (v[0] > maxX) maxX = v[0];
            plot[v[0]].insert(v[1]);
        }
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                auto p1 = points[i], p2 = points[j];
                deltaX = p2[0] - p1[0];
                if (deltaX != 0) {
                    count = 0;
                    deltaY = p2[1] - p1[1];
                    if (deltaY != 0) {
                        int deltaXA = abs(deltaX);
                        for (int k = p1[0]; k <= maxX; k += deltaXA) {
                            int y =
                                (deltaY / deltaX) * (k - p1[0]) + p1[1];
                            count += plot[k].count(y);
                        }
                        for (int k = p1[0] - deltaXA; k >= minX;
                             k -= deltaXA) {
                            int y =
                                (deltaY / deltaX) * (k - p1[0]) + p1[1];
                            count += plot[k].count(y);
                        }
                    } else {
                        // search horizontally
                        for (int k = minX; k <= maxX; k++) {
                            count += plot[k].count(p1[1]);
                        }
                    }
                    maxPoints = max(maxPoints, count);
                } else {
                    // search vertically
                    maxPoints = max(maxPoints, (int)plot[p1[0]].size());
                }
            }
        }
        return maxPoints;
    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
