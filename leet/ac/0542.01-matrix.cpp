class Solution {
  public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

        int r = mat.size(), c = mat[0].size();
        int r1 = r - 1, c1 = c - 1;

        /**
         * The biggest distance possible is the manhattan (norm 1) distance
         * of the two extremities of a diagonal := r + c
         * (PS: Everything greater than that can be considered at infinity)
         */
        const int INF = r + c;
        if (mat[0][0] == 1)
            mat[0][0] = INF;

        // Part 1: Up & Left
        /**
         * Optmization: Loog Unrolling + If Avoiding, instead of:
         *
         * [x][x][x][x]
         * [x][x][x][x]
         * [x][x][x][x]
         * [x][x][x][x]
         * for (int i = 0; i < r; i++) {
         *     for (int j = 0; j < c; j++) {
         *         int up = INF, left = INF;
         *         if (i > 0) up = mat[i - 1][j];
         *         if (j > 0) left = mat[i][j - 1];
         *         mat[i][j] = min(up, left) + 1;
         *     }
         * }
         *
         * Do:
         */

        /**
         * [ ][ ][ ][ ]
         * [x][ ][ ][ ]
         * [x][ ][ ][ ]
         * [x][ ][ ][ ]
         */
        for (int i = 1; i < r; i++) {
            if (mat[i][0] == 0)
                continue;
            mat[i][0] = mat[i - 1][0] + 1;
        }
        /**
         * [ ][x][x][x]
         * [ ][ ][ ][ ]
         * [ ][ ][ ][ ]
         * [ ][ ][ ][ ]
         */
        for (int j = 1; j < c; j++) {
            if (mat[0][j] == 0)
                continue;
            mat[0][j] = mat[0][j - 1] + 1;
        }
        /**
         * [ ][ ][ ][ ]
         * [ ][x][x][x]
         * [ ][x][x][x]
         * [ ][x][x][x]
         */
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                if (mat[i][j] == 0)
                    continue;
                mat[i][j] = min(mat[i - 1][j], mat[i][j - 1]) + 1;
            }
        }

        // Part 2: Prevously calculated & Down & Right
        /**
         * [ ][ ][ ][x]
         * [ ][ ][ ][x]
         * [ ][ ][ ][x]
         * [ ][ ][ ][ ]
         */
        for (int i = r - 2; i >= 0; i--) {
            if (mat[i][c1] == 0)
                continue;
            mat[i][c1] = min(mat[i][c1], mat[i + 1][c1] + 1);
        }
        /**
         * [ ][ ][ ][ ]
         * [ ][ ][ ][ ]
         * [ ][ ][ ][ ]
         * [x][x][x][ ]
         */
        for (int j = c - 2; j >= 0; j--) {
            if (mat[r1][j] == 0)
                continue;
            mat[r1][j] = min(mat[r1][j], mat[r1][j + 1] + 1);
        }
        /**
         * [x][x][x][ ]
         * [x][x][x][ ]
         * [x][x][x][ ]
         * [ ][ ][ ][ ]
         */
        for (int i = r - 2; i >= 0; i--) {
            for (int j = c - 2; j >= 0; j--) {
                if (mat[i][j] == 0)
                    continue;
                mat[i][j] =
                    min(mat[i][j], min(mat[i + 1][j], mat[i][j + 1]) + 1);
            }
        }

        return mat;
    }
};
