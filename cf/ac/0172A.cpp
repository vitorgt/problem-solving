#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n = 0;
    string s = "", common = "";
    cin >> n >> common;

    for (int i = 1; i < n; i++) {
        cin >> s;
        for (size_t j = 0; j < s.size() && j < 21; j++)
            if (common[j] != s[j]) {
                common = common.substr(0, j);
                break;
            }
    }

    cout << common.size() << endl;

    return 0;
}
