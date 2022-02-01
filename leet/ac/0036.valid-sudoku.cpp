class Solution { // based on https://leetcode.com/makuiyu solution
  public:        // O(n^2) memory, O(n^2) time, but more elegant
                 // leetcode data: runtime 44ms, memory 19.4mb
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> box(9, vector<bool>(9, false));
        int p = 0, k = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    k = i / 3 * 3 + j / 3;
                    p = board[i][j] - '1';
                    if (row[i][p] || col[j][p] || bow[k][p])
                        return false;
                    row[i][p] = col[j][p] = bow[k][p] = true;
                }
            }
        }
        return true;
    }
};

class SolutionB { // my solution, works great O(n) memory, O(n^2) time
  private:        // leetcode data: runtime 28ms, memory 18.7mb
    bool horizontal(vector<vector<char>> &board) {
        for (int j = 0; j < 9; j++) {
            vector<bool> line(9, false);
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    if (!line[board[i][j] - '1']) {
                        line[board[i][j] - '1'] = true;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool vertical(vector<vector<char>> &board) {
        for (int i = 0; i < 9; i++) {
            vector<bool> line(9, false);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (!line[board[i][j] - '1']) {
                        line[board[i][j] - '1'] = true;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool squares(vector<vector<char>> &board) {
        int ibase = 0, jbase = 0;
        for (int k = 0; k < 9; k++) {
            vector<bool> line(9, false);
            ibase = (k % 3) * 3 + 3;
            for (int i = ibase - 3; i < ibase; i++) {
                jbase = ((k / 3) + 1) * 3;
                for (int j = jbase - 3; j < jbase; j++) {
                    if (board[i][j] != '.') {
                        if (!line[board[i][j] - '1']) {
                            line[board[i][j] - '1'] = true;
                        } else {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        return horizontal(board) && vertical(board) && squares(board);
    }
};
