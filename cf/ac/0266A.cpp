#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n = 0;
    string s = "", a = "";
    cin >> n >> s;

    if (!n) {
        cout << 0 << endl;
        return 0;
    }

    a += s.front();

    for (size_t i = 1; i < n; i++) {
        if (s[i] != a.back())
            a += s[i];
    }

    cout << n - a.size() << endl;

    return 0;
}
