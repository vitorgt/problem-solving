class Solution {
  public:
    void fillIsland(vector<vector<char>> &grid, int i, int j) {
        if (i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size() &&
            grid[i][j] == '1') {
            grid[i][j] = '0';
            fillIsland(grid, i - 1, j);
            fillIsland(grid, i + 1, j);
            fillIsland(grid, i, j - 1);
            fillIsland(grid, i, j + 1);
        }
    }
    int numIslands(vector<vector<char>> &grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    fillIsland(grid, i, j);
                }
            }
        }
        return count;
    }
};
