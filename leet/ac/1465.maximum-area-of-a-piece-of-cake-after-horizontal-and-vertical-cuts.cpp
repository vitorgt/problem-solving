class Solution {
  public:
    int maxArea(int h, int w, vector<int>& horizontalCuts,
                vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int hS = horizontalCuts.size() - 1, vS = verticalCuts.size() - 1;
        int hMaxGap = horizontalCuts[0], vMaxGap = verticalCuts[0];

        for (size_t i = 0; i < hS; i++)
            hMaxGap = max(horizontalCuts[i + 1] - horizontalCuts[i], hMaxGap);
        hMaxGap = max(h - horizontalCuts[hS], hMaxGap);

        for (size_t i = 0; i < vS; i++)
            vMaxGap = max(verticalCuts[i + 1] - verticalCuts[i], vMaxGap);
        vMaxGap = max(w - verticalCuts[vS], vMaxGap);

        return ((long long)hMaxGap * (long long)vMaxGap) % 1000000007;
    }
};
