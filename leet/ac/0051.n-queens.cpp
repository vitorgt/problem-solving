class Solution {
  private:
    vector<vector<string>> ans;
    vector<char> positions;

    vector<unordered_set<char>> change(vector<unordered_set<char>> board,
                                       char pos, int row) {
        for (int i = row - 1; i >= 0; i--) {
            board[i].erase(pos);
            board[i].erase(pos - row + i); // pos - (row - i)
            board[i].erase(pos + row - i); // pos + (row - i)
        }
        return board;
    }

    void solve(const vector<unordered_set<char>> &board, int n) {
        if (n < 0) {
            vector<string> temp;
            for (auto p : positions) {
                string row = string(int(p), '.');
                row += 'Q';
                row += string(board.size() - p - 1, '.');
                temp.push_back(row);
            }
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i <= n; i++)
            if (board[i].empty())
                return;

        for (char i : board[n]) {
            positions.push_back(i);
            solve(change(board, i, n), n - 1);
            positions.pop_back();
        }

        return;
    }

  public:
    vector<vector<string>> solveNQueens(int n) {
        vector<unordered_set<char>> board(n);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board[i].insert(j);

        solve(board, n - 1);

        return ans;
    }
};
