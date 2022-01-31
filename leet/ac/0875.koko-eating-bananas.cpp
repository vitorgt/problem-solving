#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
  private:
    // O(n)
    bool isKValid(vector<int> piles, int k, int h) {
        int time = 0;
        for (size_t i = 0; i < piles.size(); i++) {
            // time i'll spend eating from this pile
            time += ceil(piles[i] / (float)k);
            if (time > h) return false;
        }
        return true;
    }

  public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int biggest = *max_element(piles.begin(), piles.end()), ans = biggest;

        int l = 1, m = 0, r = biggest;

        if (piles.size() == 1) return ceil(piles[0] / (float)h);
        if (piles.size() == h) return biggest;

        while (l <= r) {
            m = (l + r) / 2;
            if (isKValid(piles, m, h)) {
                ans = min(m, ans);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return ans;
    }
};

int main(int argc, const char** argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    Solution* a = new Solution();

    vector<int> b({332484035, 524908576, 855865114, 632922376, 222257295,
                   690155293, 112677673, 679580077, 337406589, 290818316,
                   877337160, 901728858, 679284947, 688210097, 692137887,
                   718203285, 629455728, 941802184});
    cout << a->minEatingSpeed(b, 823855818) << endl;
    return 0;
}
