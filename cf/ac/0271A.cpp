#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

bool isBeautiful(int y) {
    string s = to_string(y);
    char a = s[0], b = s[1], c = s[2], d = s[3];
    return (a != b && a != c && a != d && b != c && b != d && c != d);
}

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int y = 0;
    cin >> y;

    for (y++; !isBeautiful(y); y++)
        ;

    cout << y << endl;

    return 0;
}
