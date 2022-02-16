#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 0x3f3f3f3f;

int main(int argc, const char **argv) {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n = 0, b = 0, p = 0;
    priority_queue<int, vector<int>, less<int>> pq;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> b;
        pq.push(b);
        if (pq.top() == b)
            p = i;
    }

    pq.pop();
    cout << p << " " << pq.top() << endl;

    return 0;
}
