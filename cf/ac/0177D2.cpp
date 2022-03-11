#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 0x3f3f3f3f;

void slowerSolution(vector<int> &a, vector<int> &b, int c) {
    // Time: O((n - m) * m)
    for (size_t i = 0; i < a.size(); i++)
        for (size_t j = 0; j < b.size(); j++) // b.size() == m
            a[i + j] = (a[i + j] + b[j]) % c;
}

void evenSlowerSolution(vector<int> &a, vector<int> &b, int c) {
    // Time: O((n - m) * m)
    // usually 4 times slower than slowerSolution()
    for (size_t i = 0; i < a.size(); i++) // b.size() == m
        transform(a.begin() + i, a.begin() + i + b.size(), b.begin(),
                  a.begin() + i, [c](int x, int y) { return (x + y) % c; });
}

int main() {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n = 0, m = 0, c = 0;
    cin >> n >> m >> c;
    vector<int> a(n), b(m + 1);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        b[i] += b[i - 1];
    }

    for (int i = 0; i < n; i++)
        cout << (a[i] + b[min(i + 1, m)] - b[max(i - (n - m), 0)]) % c << ' ';

    return 0;
}
