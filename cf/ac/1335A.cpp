#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 0, n = 0;
    cin >> t;

    while (t--) {
        cin >> n;
        cout << (int)ceil((n / 2.0) - 1) << endl;
    }

    return 0;
}
