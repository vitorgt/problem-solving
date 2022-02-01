class Solution {
  private:
    bool validDot(string s) {
        char lastSeen = s[0];
        if (s[s.length() - 1] == '0')
            return false;
        if (s[0] == '0' && s[1] != '.')
            return false;
        for (int i = 1; s[i] != '.'; i++) {
            if (lastSeen == '0' && s[i] == '0')
                return false;
        }
        return true;
    }

    vector<string> sides(string s) {
        vector<string> possible;
        if (s.length() == 1) {
            possible.push_back(s);
        } else {
            if (s[0] != '0')
                possible.push_back(s);
            for (int i = 1; i < s.length(); i++) {
                string ldot =
                    s.substr(0, i) + '.' + s.substr(i, s.length() - i);
                if (validDot(ldot))
                    possible.push_back(ldot);
            }
        }
        return possible;
    }

  public:
    vector<string> ambiguousCoordinates(string s) {
        s = s.substr(1, s.length() - 2);
        vector<string> ans;
        for (int i = 1; i < s.length(); i++) {
            string l = s.substr(0, i);
            string r = s.substr(i, s.length() - i);
            vector<string> lpos = sides(l);
            if (!lpos.size())
                continue;
            vector<string> rpos = sides(r);
            if (!rpos.size())
                continue;
            for (int j = 0; j < lpos.size(); j++) {
                for (int k = 0; k < rpos.size(); k++) {
                    ans.push_back('(' + lpos[j] + ", " + rpos[k] + ')');
                }
            }
        }
        return ans;
    }
};
