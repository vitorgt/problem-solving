#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
  public:
    string removeKdigits(string num, int k) {
        const int n = num.length();
        const int d = n - k;
        if (k >= n) return to_string(0);
        int top = 0, i = 0;
        vector<char> st(n, 0);
        for (i = 0; i < n; i++) {
            while (top > 0 && k > 0 && st[top - 1] > num[i]) {
                top--;
                k--;
            }
            st[top++] = num[i];
        }
        for (i = 0; i < d && st[i] == '0'; i++);
        return string(st.begin() + i, st.begin() + (d - i));
    }
};
