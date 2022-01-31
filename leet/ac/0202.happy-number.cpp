class Solution {
  public:
    int squareDigitis(int n) {
        int r = 0;
        do {
            r += (n % 10) * (n % 10);
        } while (n /= 10);
        return r;
    }
    bool isHappy(int n) {
        int hare = n, tortoise = n;
        while (hare != 1) {
            hare = squareDigitis(squareDigitis(hare));
            tortoise = squareDigitis(tortoise);
            if (hare == 1) return true;
            if (hare == tortoise) {
                return false;
            }
        }
        return true;
    }
};
