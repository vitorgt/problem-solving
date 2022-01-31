#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
  public:
    string minWindow(string s, string t) {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

        int n = s.size(), m = t.size();
        int p1 = 0, p2 = 0, minLenS = 0;

        unordered_map<char, vector<int>> posS;
        for (int i = 0; i < n; i++) posS[s[i]].push_back(i);

        unordered_map<char, int> countT;
        for (int i = 0; i < m; i++) countT[t[i]]++;

        for (auto &cT : countT) {
            if (posS[cT.first].size() < cT.second) return "";
            else if (posS[cT.first].size() == cT.second) {
                p1 = min(p1, posS[cT.first][0]);
                p2 = max(p2, posS[cT.first][cT.second - 1]);
            } else {
                // i can chose
            }
        }

        return s.substr(p1, p2 - p1);
    }
};

int main(int argc, const char **argv) {
    Solution *s = new Solution();
    cout << s->minWindow("ADOBECODEBANC", "ABC") << endl;
    return 0;
}
