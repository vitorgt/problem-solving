#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n = 0;
    string a = "";
    cin >> n;

    while (n--) {
        cin >> a;
        if (a.length() > 10) {
            cout << a.front() << a.length() - 2 << a.back() << endl;
        } else {
            cout << a << endl;
        }
    }

    return 0;
}
