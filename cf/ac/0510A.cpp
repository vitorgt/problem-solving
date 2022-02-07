#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n = 0, m = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        if (!(i % 2)) {
            cout << string(m, '#') << endl;
            continue;
        }
        if (((int)ceil(i / 2.0)) % 2)
            cout << string(m - 1, '.') << "#" << endl;
        else
            cout << "#" << string(m - 1, '.') << endl;
    }

    return 0;
}
