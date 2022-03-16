#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 0x3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int a = 0, minA = 0, maxA = 0;
    ll sum = 0;

    cin >> a;
    minA = maxA = a;
    sum += a;

    while (cin >> a) {
        sum += a;
        minA = min(minA, a);
        maxA = max(maxA, a);
    }

    cout << sum - maxA << ' ' << sum - minA << endl;

    return 0;
}
