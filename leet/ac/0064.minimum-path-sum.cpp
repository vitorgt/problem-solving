class Solution {
  public:
    int minPathSum(vector<vector<int>> &grid) {
        const int l = grid.size(), c = grid[0].size();
        for (int i = 1; i < l; i++) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int i = 1; i < c; i++) {
            grid[0][i] += grid[0][i - 1];
        }
        for (int i = 1; i < l; i++) {
            for (int j = 1; j < c; j++) {
                grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
            }
        }
        return grid[l - 1][c - 1];
    }
};
