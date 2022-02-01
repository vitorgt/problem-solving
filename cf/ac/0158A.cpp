#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n = 0, k = 0, read = 0, readk = 0, adv = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++, adv++) {
        cin >> read;
        if (read <= 0) break;
        if (i + 1 == k) readk = read;
        if (read < readk) break;
    }

    cout << adv << endl;

    return 0;
}
