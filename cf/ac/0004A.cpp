#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int w = 0;
    cin >> w;
    cout << (w > 3 && !(w % 2) ? "YES" : "NO") << endl;

    return 0;
}
