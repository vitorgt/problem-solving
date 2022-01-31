#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
  public:
    int stoneGameVII(vector<int> &stones) {
        int l = -1, r = stones.size();
        int a = 0, b = 0;
        bool aTurn = true;
        vector<int> acc(1, stones[0]);
        for (size_t i = 1; i < stones.size(); i++)
            acc.push_back(stones[i] + acc[i - 1]);

        while (l < r) {
            if (aTurn) {
                if (acc[r - 1] - acc[l] > acc[r] - acc[l + 1]) {
                    a += acc[r - 1] - acc[l];
                    r--;
                } else {
                    a += acc[r] - acc[l + 1];
                    l++;
                }
                aTurn = false;
            } else {
                if (acc[r - 1] - acc[l] < acc[r] - acc[l + 1]) {
                    b += acc[r - 1] - acc[l];
                    r--;
                } else {
                    b += acc[r] - acc[l + 1];
                    l++;
                }
                aTurn = true;
            }
        }
        return abs(a - b);
    }
};

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    Solution *a = new Solution();
    vector<int> b({5, 3, 1, 4, 2});
    cout << a->stoneGameVII(b) << endl;
    return 0;
}
