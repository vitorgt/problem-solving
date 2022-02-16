#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

/**
 * Test case #27 is wrong, this is what i got from jugde.
 * They can finish level 3 that has 3 levels.
 * Player X can win levels 1 and 2, and player Y can win levels 2 and 3.
 *
 * 27
 * Time: 0 ms, memory: 8 KB
 * Verdict: WRONG_ANSWER
 *
 * Input
 * 3
 * 1 2
 * 2 2 3
 *
 * Participant's output
 * I become the guy.    (yes)
 *
 * Jury's answer
 * Oh, my keyboard!     (no)
 *
 * Checker comment
 * wrong answer 1st lines differ - expected: 'Oh, my keyboard!', found: 'I
 * become the guy.'
 */

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    unsigned long n = 0;
    string a = "", b = "";
    unordered_set<string> s;
    cin >> n;

    getline(cin, a);
    getline(cin, a);
    getline(cin, b);
    a += " " + b;

    for (size_t i = a.find(" "); i != string::npos; i = a.find(" ")) {
        s.insert(a.substr(0, i));
        a = a.substr(i + 1);
    }
    s.insert(a);

    s.erase("0"); // 0 is not a valid number but can be in the input

    if (n == s.size())
        cout << "I become the guy." << endl;
    else
        cout << "Oh, my keyboard!" << endl;

    return 0;
}
