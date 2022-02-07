#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n = 0, k = 0, ans = 0;
    cin >> n >> k;

    k = floor((240 - k) / 5.0);

    for (int i = 1; i <= n; i++, ans++) {
        k -= i;
        if (k < 0)
            break;
    }

    cout << ans << endl;

    return 0;
}
