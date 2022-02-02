#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    string s = "";
    unordered_set<char> us;
    cin >> s;

    for (size_t i = 0; i < s.size(); i++)
        us.insert(s[i]);

    if (us.size() % 2)
        cout << "IGNORE HIM!" << endl;
    else
        cout << "CHAT WITH HER!" << endl;

    return 0;
}
