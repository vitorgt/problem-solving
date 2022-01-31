#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
  public:
    bool isPossible(vector<int>& target) {
        sort(target.begin(), target.end());
        vector<long long> accSum(target.size());
        accSum[0] = target[0];
        for (int i = 1; i < target.size(); i++) {
            accSum[i] = accSum[i - 1] + target[i];
        }
    }
};

int main(int argc, const char** argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    Solution().isPossible([9, 3, 5]);
    return 0;
}
