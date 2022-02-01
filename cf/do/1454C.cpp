#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 0, n = 0, a = 0, pa = 0, i = 0, min = INF, ms = 0;
    unordered_map<int, string> desc;
    unordered_map<int, int> descS;

    cin >> t;
    while (t--) {
        cin >> n;
        n--;
        min = INF;
        desc.clear();
        cin >> a;
        desc[a] += "s";
        descS[a]++;
        for (i = 1; i < n; i++) {
            pa = a;
            cin >> a;
            if (a != pa) {
                desc[a] += "m";
                descS[a]++;
            }
        }
        cin >> a;
        if (a != pa) {
            desc[a] += 'e';
            descS[a]++;
        } else if (desc[a].length() > 1) {
            desc[a].pop_back();
            desc[a] += "e";
        } else {
            cout << 0 << endl;
            continue;
        }
        for (auto d : descS) {
            if (d.second < min) {
                i = d.first;
                min = d.second;
            }
        }
        // for (auto d : desc) {
        //     int mini = min - 1;
        //     if (d.second.length() <= mini) {
        //         int dse = 0, ise = 0;
        //         if (d.second.find('s') != string::npos) dse++;
        //         if (d.second.find('e') != string::npos) dse++;
        //         if (desc[i].find('s') != string::npos) ise++;
        //         if (desc[i].find('e') != string::npos) ise++;
        //         if (dse > ise) {
        //             i = d.first;
        //             min = d.second.length();
        //         }
        //     }
        // }
        ms = 0;
        for (char c : desc[i]) {
            if (c == 'm')
                ms++;
        }
        cout << ms + 1 << endl;
    }
    return 0;
}
