#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 0x3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n = 0, k = 0, empty = 0, read = 0;
    ll ans = 0;
    cin >> n >> k;

    vector<int> a(n, 0);
    vector<vector<int>> v(k);
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        cin >> read;
        v[a[i] - 1].push_back(read);
    }

    for (int i = 0; i < k; i++)
        if (v[i].empty()) {
            empty++;
            continue;
        } else if (v[i].size() > 1) {
            sort(v[i].rbegin(), v[i].rend());
            for (size_t j = 1; j < v[i].size(); j++)
                pq.push(v[i][j]);
        }

    while (empty--) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans << endl;

    return 0;
}
