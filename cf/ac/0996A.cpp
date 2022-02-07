#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n = 0, ans = 0;
    vector<int> m{100, 20, 10, 5, 1};
    cin >> n;

    for (size_t i = 0; n && i < m.size(); i++)
        if (n >= m[i]) {
            ans += n / m[i];
            n %= m[i];
        }

    cout << ans << endl;

    return 0;
}
