#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n = 0, t = 0;
    string s = "", s2 = "";
    cin >> n >> t >> s;
    s2 = s;

    while (t--) {
        for (size_t i = 1; i < s.size(); i++)
            if (s[i - 1] == 'B' && s[i] == 'G')
                swap(s2[i - 1], s2[i]);
        s = s2;
    }

    cout << s2 << endl;

    return 0;
}
