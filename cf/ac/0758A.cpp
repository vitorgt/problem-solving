#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n = 0, a = 0, max_el = 0;
    ll sum_a = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        sum_a += a;
        max_el = max(max_el, a);
    }

    cout << ((n * max_el) - sum_a) << endl;

    return 0;
}
