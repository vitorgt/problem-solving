#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 0, n = 0, k = 0, i = 0, sum = 0;
    cin >> t;

    while (t--) {
        sum = 0;
        cin >> n >> k;
        vector<int> a(n), b(n);

        for (i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        for (i = 0; i < n; i++)
            cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());

        for (i = 0; i < n && k && a[i] < b[i]; i++, k--)
            sum += (b[i] - a[i]);

        cout << sum << endl;
    }

    return 0;
}
