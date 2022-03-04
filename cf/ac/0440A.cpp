#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n = 0, a = 0;
    cin >> n;
    ll sum = 0, total = n;

    for (int i = 1; i < n; i++) {
        cin >> a;
        sum += a;
        total += i;
    }

    cout << total - sum << endl;

    return 0;
}
