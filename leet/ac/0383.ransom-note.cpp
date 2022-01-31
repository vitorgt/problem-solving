class Solution {  // O(n) time, O(1) memory
  public:
    bool canConstruct(string ransomNote, string magazine) {
        int r = 0, m = 0;
        const int rl = ransomNote.length(), ml = magazine.length();
        if (ml < rl) return false;
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        for (; r < rl && m < ml; r++) {
            while (ransomNote[r] > magazine[m] && m < ml) {
                m++;
            }
            if (ransomNote[r] == magazine[m]) {
                m++;
            } else {
                break;
            }
        }
        if (r < rl) return false;
        return true;
    }
};

class SolutionB {  // O(n) time, O(n) memory
  public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> freq;
        for (char c : magazine) {
            freq[c]++;
        }
        for (char c : ransomNote) {
            if (freq[c] > 0) {
                freq[c]--;
            } else {
                return false;
            }
        }
        return true;
    }
};
