#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 0, n = 0, a = 0, last = -1, count = 0;
    cin >> t;
    while (t--) {
        cin >> n;
        last = -1;
        count = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            if (a == 1)
                last = i;
            else
                count++;
            if (last == -1)
                count = 0;
        }
        cout << count - (n - last) << endl;
    }
    return 0;
}
