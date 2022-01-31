class Solution {
  public:
    vector<int> twoSum(vector<int> &ns, int t) {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

        int l = 0, r = ns.size() - 1;

        while (l < r) {
            if (ns[l] + ns[r] == t) return {l + 1, r + 1};
            else if (ns[l] + ns[r] > t)
                r--;
            else
                l++;
        }

        return {};
    }
};
