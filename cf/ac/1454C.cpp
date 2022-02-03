#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 0, n = 0, a = 0, a_prev = 0, first = 0;
    unordered_map<int, int> breaks;
    cin >> t;

    while (t--) {
        breaks.clear();
        cin >> n >> first;
        n--;
        a = first;
        a_prev = first;

        while (n--) {
            cin >> a;
            if (a != a_prev)
                breaks[a]++;
            a_prev = a;
        }

        if (breaks.find(first) == breaks.end())
            breaks[first] = 0;
        for (auto b : breaks)
            if (b.first != a)
                breaks[b.first]++;

        a_prev = INF;
        for (auto b : breaks)
            if (b.second < a_prev)
                a_prev = b.second;

        cout << (a_prev == INF ? 0 : a_prev) << endl;
    }

    return 0;
}
