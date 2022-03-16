#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 0x3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int h = 0;
    string s = "";
    cin >> s;

    h = stoi(s.substr(0, 2));

    if (s[8] == 'A') {
        if (h == 12)
            cout << "00";
        else
            cout << s.substr(0, 2);
    } else {
        if (h == 12)
            cout << s.substr(0, 2);
        else
            cout << h + 12;
    }

    cout << s.substr(2, 6) << endl;

    return 0;
}
