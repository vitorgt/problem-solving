#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 0, n = 0, i = 0;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << n << " ";
        n--;
        for (i = 1; i < n; i++) {
            cout << i << " ";
        }
        cout << i << endl;
    }
    return 0;
}
