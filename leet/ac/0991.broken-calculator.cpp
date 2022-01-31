class Solution {  // based on https://leetcode.com/lee215 solution
  public:
    int brokenCalc(int X, int Y) {
        int ans = 0;
        while (Y > X) {
            Y = Y % 2 ? Y + 1 : Y / 2;
            ans++;
        }
        return ans + X - Y;
    }
};

class SolutionB {  // doesnt work :c
  private:
    const int INF = 0x3f3f3f3f;
    int maxOp = INF;
    int Y, YY;
    unordered_map<int, bool> vis;
    void dp(int X, int op) {
        if (op <= maxOp) {
            if (X == Y) {
                maxOp = op;
                return;
            } else if (X < YY && X >= 1) {
                int xX = X * 2;
                if (!vis[xX]) {
                    vis[xX] = true;
                    cout << xX << "|";
                    dp(xX, op + 1);
                }
                if (!vis[X - 1]) {
                    vis[X - 1] = true;
                    cout << X - 1 << "|";
                    dp(X - 1, op + 1);
                }
            }
        }
    }

  public:
    int brokenCalc(int X, int Y) {
        if (X >= Y) return X - Y;
        this->Y = Y;
        this->YY = Y * 2;
        dp(X, 0);
        return maxOp;
    }
};
