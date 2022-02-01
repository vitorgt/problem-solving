#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int m = 0, n = 0, fits = 0;
    cin >> m >> n;

    while (m > 0 && n > 0) {
        if (m == 1 && n == 1) {
            break;
        } else if (m == 1 || n == 1) {
            fits += floor(max(m, n) / 2.0);
            break;
        } else {
            fits += floor(m / 2.0) * n;
            m -= floor(m / 2.0) * 2;
        }
    }

    cout << fits << endl;

    return 0;
}
