#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    string a = "", b = "", c = "";
    cin >> a >> b >> c;

    if (a.size() + b.size() != c.size()) {
        cout << "NO" << endl;
        return 0;
    }

    unordered_map<char, int> m;

    for (char i : a)
        m[i]++;
    for (char i : b)
        m[i]++;
    for (char i : c)
        m[i]--;

    for (auto i : m)
        if (i.second) {
            cout << "NO" << endl;
            return 0;
        }

    cout << "YES" << endl;
    return 0;
}
