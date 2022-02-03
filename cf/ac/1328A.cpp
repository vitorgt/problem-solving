#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 0, a = 0, b = 0;
    cin >> t;

    while (t--) {
        cin >> a >> b;
        cout << (a % b == 0 ? 0 : b - a % b) << endl;
    }

    return 0;
}
