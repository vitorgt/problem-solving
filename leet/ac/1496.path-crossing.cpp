class Solution {
  public:
    bool isPathCrossing(string path) {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

        unordered_set<pair<int, int>> visited;
        int x = 0, y = 0;
        visited.insert({x, y});

        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == 'N')
                ++y;
            else if (path[i] == 'S')
                --y;
            else if (path[i] == 'E')
                ++x;
            else if (path[i] == 'W')
                --x;

            if (visited.count({x, y}))
                return true;
            else
                visited.insert({x, y});
        }
        return false;
    }
};
