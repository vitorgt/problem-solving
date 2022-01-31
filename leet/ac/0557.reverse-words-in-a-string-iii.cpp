class Solution {
  public:
    string reverseWords(string s) {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        int lastBegin = 0, half = 0, ss = s.size() - 1;
        for (int i = 0; i <= ss; i++) {
            if (s[i] == ' ' || i == ss) {
                if (i == ss) i++;
                half = (i - lastBegin) / 2 + lastBegin;
                for (int j = lastBegin, k = i - 1; j < half; j++, k--) {
                    swap(s[j], s[k]);
                }
                lastBegin = i + 1;
            }
        }
        return s;
    }
};
