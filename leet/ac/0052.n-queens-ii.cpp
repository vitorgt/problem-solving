class Solution {
  private:
    vector<unordered_set<char>> change(vector<unordered_set<char>> board,
                                       char pos, int row) {
        for (int i = row - 1; i >= 0; i--) {
            board[i].erase(pos);
            board[i].erase(pos - row + i); // pos - (row - i)
            board[i].erase(pos + row - i); // pos + (row - i)
        }
        return board;
    }

    int solve(const vector<unordered_set<char>> &board, int n) {
        if (n < 0)
            return 1;

        for (int i = 0; i <= n; i++)
            if (board[i].empty())
                return 0;

        int success = 0;

        for (char i : board[n])
            success += solve(change(board, i, n), n - 1);

        return success;
    }

  public:
    int totalNQueens(int n) {
        vector<unordered_set<char>> board(n);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board[i].insert(j);

        return solve(board, n - 1);
    }
};
