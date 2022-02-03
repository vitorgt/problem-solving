#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    string s = "", r = "";
    cin >> s;

    // r only contains 4 and 7 from s
    copy_if(s.begin(), s.end(), back_inserter(r),
            [](char c) { return c == '4' || c == '7'; });

    // s gets the length of r (filtered) as string
    s = to_string(r.size());
    r = "";

    // filter length to only contain 4 and 7
    copy_if(s.begin(), s.end(), back_inserter(r),
            [](char c) { return c == '4' || c == '7'; });

    // if filtered and original lengths are equal, it only has 4 and 7
    cout << (s.size() == r.size() ? "YES" : "NO") << endl;

    return 0;
}
