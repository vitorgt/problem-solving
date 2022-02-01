#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 0, n = 0, a = 0;
    bool diff = 0;
    vector<int> as;
    cin >> t;
    while (t--) {
        cin >> n;
        diff = 0;
        vector<bool> vis(n);
        as.clear();
        for (int i = 1; i <= n; i++) {
            cin >> a;
            as.push_back(a);
            if (a != as[0])
                diff = 1;
        }
        if (!diff)
            cout << "NO\n";
        else {
            cout << "YES\n";
            int i = 0, diff = 0;
            for (i = 1; i < n; i++) {
                if (as[i] != as[0]) {
                    cout << 1 << " " << i + 1 << endl;
                    diff = i;
                }
            }
            for (int i = 1; i < n; i++) {
                if (as[i] == as[0]) {
                    cout << diff + 1 << " " << i + 1 << endl;
                }
            }
        }
    }
    return 0;
}
