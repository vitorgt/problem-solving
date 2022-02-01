#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    string a = "", b = "";
    cin >> a >> b;

    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);

    for (int i = 0; i < a.length(); i++) {
        if (a[i] == b[i]) {
            continue;
        } else if (a[i] > b[i]) {
            cout << 1 << endl;
            return 0;
        } else if (a[i] < b[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
