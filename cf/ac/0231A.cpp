#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n = 0, a = 0, b = 0, c = 0, willdo = 0;
    cin >> n;

    while (n--) {
        cin >> a >> b >> c;
        if (a + b + c > 1)
            willdo++;
    }

    cout << willdo << endl;

    return 0;
}
