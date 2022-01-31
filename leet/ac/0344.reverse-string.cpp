class Solution {
  public:
    void reverseString(vector<char> &s) {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        int ss = s.size() / 2;
        for (int i = 0, j = s.size() - 1; i < ss; i++, j--) swap(s[i], s[j]);
    }
};
