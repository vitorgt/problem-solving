#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    string s = "", U = "", l = "";
    cin >> s;

    copy_if(s.begin(), s.end(), back_inserter(U),
            [](char c) { return isupper(c); });
    copy_if(s.begin(), s.end(), back_inserter(l),
            [](char c) { return islower(c); });

    if (U.size() > l.size())
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    else
        transform(s.begin(), s.end(), s.begin(), ::tolower);

    cout << s << endl;

    return 0;
}
