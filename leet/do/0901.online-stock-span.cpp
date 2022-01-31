#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

class StockSpanner {
  private:
    int day;
    map<int, int> span;

  public:
    StockSpanner() {
        this->day = 0;
    }

    int next(int price) {
        cout << "in " << price << endl;
        auto f = span.upper_bound(price);
        int last = 0;
        if (f != span.end()) {
            for (; f != span.end(); f = std::next(f, 1)) {
                cout << f->first << "|" << f->second << endl;
                last = max(last, f->second);
            }
            last = this->day - last;
        } else {
            last = 1;
        }
        span[price] = this->day;
        this->day++;
        return last;
    }
};
