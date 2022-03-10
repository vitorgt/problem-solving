#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 0x3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n = 0, log2n = 0, i = 0;
    ll count = 0;
    cin >> n;
    vector<ll> a(n);
    log2n = floor(log2(n));

    for (i = 0; i < n; i++)
        cin >> a[i];

    for (i = 0; i < n - 1; i++) {
        while ((1 << log2n) + i >= n)
            log2n--;
        a[(1 << log2n) + i] += a[i];
        count += a[i];
        a[i] = 0;
        cout << count << endl;
    }

    return 0;
}
