#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 0, n = 0, last = 0;
    unordered_map<int, int> acc_sum;
    cin >> t;
    for (int i = 1; i <= 9; i++) {
        n = i;
        acc_sum[n] = acc_sum[last] + 1;
        last = n;
        for (int j = 2; j <= 4; j++) {
            n = n * 10 + i;
            acc_sum[n] = acc_sum[last] + j;
            last = n;
        }
    }
    while (t--) {
        cin >> n;
        cout << acc_sum[n] << endl;
    }
    return 0;
}
