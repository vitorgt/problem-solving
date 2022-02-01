class Solution {
  private:
    bool isPalindrome(string a) {
        int l = 0, r = a.size() - 1;
        while (l < r)
            if (a[l++] != a[r--])
                return false;
        return true;
    }

  public:
    vector<vector<int>> palindromePairs(vector<string> &words) {
        vector<vector<int>> ans;
        unordered_map<string, int> mp;
        const size_t n = words.size();

        for (int i = 0; i < n; i++)
            // storing the reverse of each word
            mp[string(words[i].rbegin(), words[i].rend())] = i;

        if (mp.count(""))
            for (int i = 0; i < n; i++)
                if (i != mp[""] && isPalindrome(words[i]))
                    ans.push_back({i, mp[""]}), ans.push_back({mp[""], i});
        mp.erase("");

        for (int i = 0; i < n; i++) {
            string l = "", r = "";
            for (size_t j = 0; j < words[i].size(); j++) {
                l.push_back(words[i][j]);
                r = words[i].substr(j + 1);
                if (mp.count(l) && i != mp[l] && isPalindrome(r))
                    ans.push_back({i, mp[l]});
                if (mp.count(r) && i != mp[r] && isPalindrome(l))
                    ans.push_back({mp[r], i});
            }
        }

        return ans;
    }
};

class SolutionA { // works, tle
  private:
    bool isPalindrome(string a) {
        int l = 0, r = a.size() - 1;
        while (l < r)
            if (a[l++] != a[r--])
                return false;
        return true;
    }

  public:
    vector<vector<int>> palindromePairs(vector<string> &words) {
        vector<vector<int>> ans;
        if (words.size() == 1)
            return ans;
        for (size_t i = 0; i < words.size(); i++) {
            for (size_t j = i + 1; j < words.size(); j++) {
                if (isPalindrome(words[i] + words[j])) {
                    ans.push_back({i, j});
                }
                if (isPalindrome(words[j] + words[i])) {
                    ans.push_back({j, i});
                }
            }
        }
        return ans;
    }
};
