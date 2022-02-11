#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 0, x = 0, y = 0, n = 0, m = 0;
    cin >> t;

    while (t--) {
        cin >> x >> y >> n;
        m = (n % x) - y;

        if (m < 0)
            cout << n - x - m << endl;
        else
            cout << n - m << endl;
    }

    return 0;
}
