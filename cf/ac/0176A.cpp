#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 0x3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n = 0, m = 0, k = 0, usedK = 0, combinationProfit = 0, ans = 0;
    string uselessNames = "";
    cin >> n >> m >> k;

    vector<vector<vector<int>>> v(n, vector<vector<int>>(m, vector<int>(3, 0)));
    struct cmp {
        auto operator()(const pair<int, int> &a, const pair<int, int> &b) const
            -> bool {
            return a.second < b.second;
        }
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> profit;

    for (int i = 0; i < n; i++) {
        cin >> uselessNames;
        for (int j = 0; j < m; j++) {
            cin >> v[i][j][0] >> v[i][j][1] >> v[i][j][2];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            usedK = 0, combinationProfit = 0;
            if (i == j)
                continue;
            for (int l = 0; l < m; l++) {
                profit.push(make_pair(
                    l, (v[i][l][2] == 0) ? 0 : v[j][l][1] - v[i][l][0]));
            }
            while (!profit.empty()) {
                auto p = profit.top();
                profit.pop();
                if (p.second <= 0)
                    continue;
                int qnt = min(v[i][p.first][2], k - usedK);
                usedK += qnt;
                combinationProfit += p.second * qnt;
                ans = max(ans, combinationProfit);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
