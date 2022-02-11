#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n = 0, w = 0, a = 0;
    cin >> n;
    vector<vector<int>> t(3);

    for (int i = 1; i <= n; i++) {
        cin >> a;
        t[a - 1].push_back(i);
    }

    w = min(t[0].size(), min(t[1].size(), t[2].size()));
    cout << w << endl;

    for (int i = 0; i < w; i++)
        cout << t[0][i] << " " << t[1][i] << " " << t[2][i] << endl;

    return 0;
}
