class Solution {  // based on https://leetcode.com/nathanni solution
  public:
    vector<int> findAnagrams(string s, string p) {
        const int sl = s.length(), pl = p.length();
        int left = 0, right = 0, count = pl;
        vector<int> ans;
        if (pl > sl) return ans;
        vector<int> hash('z' + 1, 0);
        for (char c : p) {
            hash[c]++;
        }
        while (right < sl) {
            if (hash[s[right]] >= 1) {
                count--;
            }
            hash[s[right]]--;
            right++;
            if (count == 0) {
                ans.push_back(left);
            }
            if (right - left == pl) {
                if (hash[s[left]] >= 0) {
                    count++;
                }
                hash[s[left]]++;
                left++;
            }
        }
        return ans;
    }
};

class SolutionB {  // my solution works, but slower
  public:
    vector<int> findAnagrams(string s, string p) {
        const int sl = s.length(), pl = p.length();
        vector<int> ans;
        if (pl > sl) return ans;
        sort(p.begin(), p.end());
        for (int i = 0; i + pl <= sl; i++) {
            string c(s.begin() + i, s.begin() + i + pl);
            sort(c.begin(), c.end());
            if (c == p) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
