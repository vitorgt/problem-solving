#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int m = 0, n = 0, one = 0;

    for (m = 0; m < 5 && !one; m++) {
        for (n = 0; n < 5 && !one; n++) {
            cin >> one;
        }
    }

    cout << abs(m - 3) + abs(n - 3) << endl;

    return 0;
}
