#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
  public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>> &matrix) {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        int n = matrix.size(), m = matrix[0].size();
        map<int, vector<pair<int, int>>> flat;
        vector<vector<int>> ans(n, vector<int>(m, 0));

        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < m; j++)
                flat[matrix[i][j]].push_back(make_pair(i, j));

        for (auto &p : flat) {
            map<int, vector<pair<int, int>>> flatp;
            for (size_t pp = 0; pp < p.second.size(); pp++) {
                int maxValue = 0;

                for (size_t i = 0; i < n; i++)
                    maxValue = max(maxValue, ans[i][p.second[pp].second]);

                for (size_t j = 0; j < m; j++)
                    maxValue = max(maxValue, ans[p.second[pp].first][j]);

                ans[p.second[pp].first][p.second[pp].second] = maxValue + 1;
                flatp[maxValue + 1].push_back(p.second[pp]);
            }

            for (auto &pp : flatp) {
                int last = 0;
                pair<int, int> lastp;
                for (auto i = pp.second.rbegin(); i != pp.second.rend();
                     i = next(i)) {
                    if (last && last != i->first &&
                        (i->second.first == lastp.first ||
                         i->second.second == lastp.second)) {
                        ans[i->second.first][i->second.second] = last;
                    }
                    last = i->first;
                    lastp = i->second;
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char **argv) {
    Solution *solution = new Solution();
    vector<vector<int>> matrix = {{-37, -50, -3, 44},
                                  {-37, 46, 13, -32},
                                  {47, -42, -3, -40},
                                  {-17, -22, -39, 24}};
    vector<vector<int>> ans = solution->matrixRankTransform(matrix);
    for (auto &row : ans) {
        for (auto &col : row) cout << col << ' ';
        cout << '\n';
    }
    return 0;
}
