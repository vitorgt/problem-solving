class Solution {
  public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0;
        const int h = haystack.length(), n = needle.length();
        int i = 0, j = 0;
        for (i = 0; i < h && i + n <= h; i++) {
            for (j = 0;
                 j < n && i + j < h && haystack[i + j] == needle[j];
                 j++);
            if (j == n) return i;
        }
        return -1;
    }
};
