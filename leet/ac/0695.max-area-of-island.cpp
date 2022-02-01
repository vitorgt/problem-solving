class Solution {
  private:
    int fill(vector<vector<int>> &island, int x, int y) {
        if (x < 0 || x >= island.size() || y < 0 || y >= island[x].size() ||
            !island[x][y])
            return 0;

        island[x][y] = 0;
        return 1 + fill(island, x + 1, y) + fill(island, x, y + 1) +
               fill(island, x - 1, y) + fill(island, x, y - 1);
    }

  public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        int greatest = 0;
        for (size_t i = 0; i < grid.size(); i++)
            for (size_t j = 0; j < grid[i].size(); j++)
                if (grid[i][j])
                    greatest = max(fill(grid, i, j), greatest);
        return greatest;
    }
};
