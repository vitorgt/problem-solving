#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 0x3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cout << fixed << setprecision(6);

    int n = 0, pos = 0, neg = 0, zero = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i : a)
        if (i > 0)
            pos++;
        else if (i < 0)
            neg++;
        else
            zero++;

    cout << (double)pos / n << endl;
    cout << (double)neg / n << endl;
    cout << (double)zero / n << endl;

    return 0;
}
