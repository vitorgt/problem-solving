class Solution {
  private:
    int originalColor = -1;

  public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int newColor) {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() ||
            image[sr][sc] == newColor)
            return image;
        if (originalColor == -1)
            originalColor = image[sr][sc];
        if (image[sr][sc] == originalColor) {
            image[sr][sc] = newColor;
            floodFill(image, sr - 1, sc, newColor);
            floodFill(image, sr + 1, sc, newColor);
            floodFill(image, sr, sc - 1, newColor);
            floodFill(image, sr, sc + 1, newColor);
        }
        return image;
    }
};
