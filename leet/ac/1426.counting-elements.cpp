class Solution {
  public:
    int countElements(vector<int> &arr) {
        set<int> a(arr.begin(), arr.end());
        int c = 0;
        for (int i : arr) {
            if (a.count(i + 1) == 1) {
                c++;
            }
        }
        return c;
    }
};
