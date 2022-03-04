#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    size_t i = 0, j = 0;
    string h = "heidi", s = "";
    cin >> s;

    for (i = 0, j = 0; i < h.size() && j < s.size(); j++)
        if (s[j] == h[i])
            i++;

    cout << (i == h.size() ? "YES" : "NO") << endl;

    return 0;
}
