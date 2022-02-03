#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n = 0, a = 0, b = 0, ans = 0;
    unordered_multiset<int> h;
    vector<int> g;

    cin >> n;

    while (n--) {
        cin >> a >> b;
        h.insert(a);
        g.push_back(b);
    }

    for (int i : g)
        ans += h.count(i);

    cout << ans << endl;

    return 0;
}
