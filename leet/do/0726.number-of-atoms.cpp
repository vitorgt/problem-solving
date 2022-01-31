#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
  public:
    string countOfAtoms(string formula) {
        stack<int> mulTrack;
        unordered_map<string, int> out;
        int mul = 1, tenPower = 0;
        string el = "";
        for (int i = formula.length() - 1; i >= 0; i--) {
            if ('0' < formula[i] && formula[i] < '9') {
                el = "";
                int num = 0;
                if (tenPower) {
                    int top = mulTrack.top();
                    mulTrack.pop();
                    mul /= top;
                    num = top + (formula[i] - '0') * pow(10, tenPower);
                } else {
                    num = formula[i] - '0';
                }
                multiplier.push(num);
                mul *= num;
                tenPower++;
            } else if ('a' < formula[i] && formula[i] < 'z') {
                el = formula[i] + el;
                tenPower = 0;
            } else if ('A' < formula[i] && formula[i] < 'Z') {
                el = formula[i] + el;
                tenPower = 0;
                out[el] += mul;
            } else if (formula[i] == '(') {
                el = "";
                tenPower = 0;
                mul /= mulTrack.top();
                mulTrack.pop();
            } else if (formula[i] == ')') {
                el = "";
                if (!tenPower) {
                    multiplier.push(1);
                }
                tenPower = 0;
            }
        }
    }
};
