#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int a = 0;
    priority_queue<int, vector<int>, less<int>> pq;

    for (int i = 0; i < 4; i++) {
        cin >> a;
        pq.push(a);
    }

    for (a = pq.top(), pq.pop(); !pq.empty(); pq.pop())
        cout << a - pq.top() << ' ';
    cout << endl;

    return 0;
}
