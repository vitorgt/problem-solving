#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 0x3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int l = 0, r = 0, n = 0;
    string a = "";
    cin >> a;

    r = a.size() - 1;

    while (l < r) {
        if (a[l] == a[r]) {
            n = 2;
            while (l + 1 < r && a[l + 1] == a[r])
                l++, n++;
            while (l + 1 < r && a[l] == a[r - 1])
                r--, n++;

            if (n < 3 && l + 1 < r) {
                cout << 0 << endl;
                return 0;
            }
            l++, r--;
        } else {
            cout << 0 << endl;
            return 0;
        }
    }

    if (l > r)
        cout << n + 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}
