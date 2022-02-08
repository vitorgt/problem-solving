#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 0, n = 0, i = 0;
    cin >> t;

    while (t--) {
        cin >> n;

        if (n % 4 == 0) {
            cout << "YES" << endl;

            // print even
            for (i = 2; i <= n; i += 2)
                cout << i << " ";

            // print odd
            for (i = 1; i < n - 1; i += 2)
                cout << i << " ";

            // print last
            cout << i + n / 2 << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
