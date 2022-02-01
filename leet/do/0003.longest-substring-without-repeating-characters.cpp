#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

        int ss = s.size(), maxSubS = 0;
        if (ss < 2)
            return ss;

        unordered_map<char, int> m;

        for (int i = 0, j = 0; i < ss; i++) {
            if (m.find(s[i]) != m.end()) {
                j = max(j, m[s[i]] + 1);
            }
            m[s[i]] = i;
            maxSubS = max(maxSubS, i - j + 1);
        }

        return maxSubS;
    }
};

class SolutionB { // Fails
  public:
    int lengthOfLongestSubstring(string s) {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

        size_t ss = s.size(), maxSubS = 0;
        if (ss < 2)
            return ss;

        unordered_set<char> us;

        for (int i = 0; i < ss; i++) {
            if (us.find(s[i]) == us.end()) {
                us.insert(s[i]);
            } else {
                maxSubS = max(maxSubS, us.size());
                us.clear();
                us.insert(s[i]);
            }
        }

        maxSubS = max(maxSubS, us.size());
        us.clear();

        for (int i = ss - 1; i >= 0; i--) {
            if (us.find(s[i]) == us.end()) {
                us.insert(s[i]);
            } else {
                maxSubS = max(maxSubS, us.size());
                us.clear();
                us.insert(s[i]);
            }
        }

        maxSubS = max(maxSubS, us.size());

        return (int)maxSubS;
    }
};

int main(int argc, const char **argv) {
    auto a = new Solution();
    cout << a->lengthOfLongestSubstring("asjrgapa") << endl;
    return 0;
}
