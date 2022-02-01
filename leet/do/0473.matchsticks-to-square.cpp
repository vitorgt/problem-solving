#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
  public:
    bool makesquare(vector<int> &matchsticks) {
        if (matchsticks.size() <= 3)
            return false;

        int s = accumulate(matchsticks.begin(), matchsticks.end());

        map<int, int> m;
        for (size_t i = 0; i < matchsticks.size(); i++)
            m[matchsticks[i]]++;

        if (s % 4 || m.rbegin()->first > s / 4)
            return false;

        vector<int> p(4, 0);

        for (auto i = m.rbegin(); i != m.rend(); i = next(i)) {
            for (size_t j = 0; j < 4; j++) {
                if (p[j] +) {
                }
            }
        }
    }
};

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    ;
    return 0;
}
