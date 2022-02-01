class Solution {
  public:
    int findMinArrowShots(vector<vector<int>> &points) {
        const int n = points.size();
        if (n == 0)
            return 0;
        sort(points.begin(), points.end(),
             [](vector<int> &i, vector<int> &j) { return i[1] < j[1]; });
        int ans = 1, maxX = points[0][1];
        for (int i = 1; i < n; ++i) {
            if (points[i][0] > maxX) {
                ans++;
                maxX = points[i][1];
            }
        }
        return ans;
    }
};

class SolutionB { // my solution works, but slower
  public:
    int findMinArrowShots(vector<vector<int>> &points) {
        const int n = points.size();
        if (n == 0)
            return 0;
        sort(points.begin(), points.end());
        map<int, int> arrows;
        map<int, int>::iterator it;
        arrows[points[0][0]] = points[0][1];
        for (int i = 1; i < n; i++) {
            it = arrows.find(points[i][0]);
            if (it != arrows.end()) {
                if (points[i][1] < it->second) {
                    it->second = points[i][1];
                }
            } else {
                // not found, get the lower and the greater than
                // points[i][0]
                bool fit = false;
                auto itt = arrows.equal_range(points[i][0]);
                if (itt.first != arrows.begin()) {
                    itt.first = prev(itt.first, 1);
                }
                if (itt.second != arrows.end()) {
                    itt.second = next(itt.second, 1);
                }
                for (it = itt.first; it != itt.second; it = next(it, 1)) {
                    if ((it->first <= points[i][0] &&
                         points[i][0] <= it->second) ||
                        (it->first <= points[i][1] &&
                         points[i][1] <= it->second)) {
                        // ok this arrow can kill this ballon
                        // restrict range..
                        if (points[i][1] < it->second) {
                            it->second = points[i][1];
                        }
                        if (points[i][0] > it->first) {
                            int highX = it->second;
                            arrows.erase(it->first);
                            arrows[points[i][0]] = highX;
                        }
                        fit = true;
                        break;
                    }
                }
                if (!fit) {
                    arrows[points[i][0]] = points[i][1];
                }
            }
        }
        return arrows.size();
    }
};
