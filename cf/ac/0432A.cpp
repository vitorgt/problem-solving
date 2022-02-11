#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n = 0, k = 0, g = 0, n_groups = 0;
    cin >> n >> k;
    vector<int> a(n, 0);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    for (size_t i = 0; i < a.size() && a[i] + k <= 5; i++, g++)
        if (g == 2) {
            n_groups++;
            g = -1;
        }

    cout << n_groups << endl;

    return 0;
}
