#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 0, n = 0, a = 0;
    bool found = 0;
    vector<int> p;
    map<int, vector<int>> pi;
    cin >> t;
    while (t--) {
        cin >> n;
        found = 0;
        p.clear();
        pi.clear();
        for (int i = 0; i < n; i++) {
            cin >> a;
            p.push_back(a);
            pi[a].push_back(i);
        }
        if (pi.size() == 1) {
            cout << -1 << endl;
            continue;
        }
        for (auto &&i = pi.rbegin(); i != pi.rend() && !found;
             i = next(i)) {
            for (int j : i->second) {
                if ((j > 0 && p[j - 1] < p[j]) ||
                    (j < n - 1 && p[j + 1] < p[j])) {
                    cout << j + 1 << endl;
                    found = 1;
                    break;
                }
            }
        }
    }
    return 0;
}
