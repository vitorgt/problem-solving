#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int d = 0, damaged = 0;
    vector<int> p(4);
    cin >> p[0] >> p[1] >> p[2] >> p[3] >> d;

    if (p[0] == 1 || p[1] == 1 || p[2] == 1 || p[3] == 1) {
        cout << d << endl;
        return 0;
    }

    // if we need to worry about zero
    // p.erase(find(p.begin(), p.end(), 0));

    for (int i = 1; i <= d; i++)
        for (int j : p)
            if (i % j == 0) {
                damaged++;
                break;
            }

    cout << damaged << endl;

    return 0;
}
