class Solution {
  private:
    int backspaceCalc(string A, int i) {
        int c = 0;
        while (i >= 0 && A[i] == '#') {
            c++;
            i--;
            while (i >= 0 && A[i] != '#' && c > 0) {
                c--;
                i--;
            }
        }
        return i;
    }

  public:
    bool backspaceCompare(string S, string T) {
        int iS = S.size() - 1, iT = T.size() - 1;
        while (iS >= 0 && iT >= 0) {
            iS = backspaceCalc(S, iS);
            iT = backspaceCalc(T, iT);
            if (iS >= 0 && iT >= 0) {
                if (S[iS] == T[iT]) {
                    iS--;
                    iT--;
                } else {
                    return false;
                }
            } else if (iS < 0 && iT < 0) {
                return true;
            } else {
                return false;
            }
        }
        iS = backspaceCalc(S, iS);
        iT = backspaceCalc(T, iT);
        if ((iS == -1 || iT == -1) && (iS >= 0 || iT >= 0)) {
            return false;
        }
        return true;
    }
};
