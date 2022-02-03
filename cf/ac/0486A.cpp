#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    long long n = 0;
    cin >> n;
    cout << ((n % 2) ? -1 : 1) * (long long)ceil(n / 2.0) << endl;

    return 0;
}
