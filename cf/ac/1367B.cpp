#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 0, n = 0, a = 0, wrong_even = 0, wrong_odd = 0;
    cin >> t;

    while (t--) {
        wrong_even = 0, wrong_odd = 0;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> a;

            if (i % 2 && !(a % 2))
                wrong_even++;
            else if (!(i % 2) && a % 2)
                wrong_odd++;
        }

        if (wrong_even != wrong_odd)
            cout << -1 << endl;
        else
            cout << wrong_even << endl;
    }

    return 0;
}
