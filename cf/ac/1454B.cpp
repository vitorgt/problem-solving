#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 0, n = 0, a = 0;
    set<int> used;
    map<int, int> potential;

    cin >> t;
    while (t--) {
        used.clear();
        potential.clear();
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            if (used.find(a) == used.end()) {
                if (potential.find(a) == potential.end()) {
                    potential[a] = i;
                } else {
                    potential.erase(a);
                    used.insert(a);
                }
            }
        }
        if (potential.empty()) {
            cout << -1 << endl;
        } else {
            cout << potential.begin()->second << endl;
        }
    }
    return 0;
}
