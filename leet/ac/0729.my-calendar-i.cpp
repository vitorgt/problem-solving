class MyCalendarWOW {
  private:
    map<int, int> s;

  public:
    MyCalendarWOW() {}

    bool book(int start, int end) {
        auto it = s.upper_bound(start);
        if (it != s.end() && (*it).second < end) return false;
        s[end] = start;
        return true;
    }
};

class MyCalendar {
  private:
    set<int> s, e;

    bool insert(int start, int end) {
        s.insert(start);
        e.insert(end);
        return true;
    }

  public:
    MyCalendar() {}

    bool book(int start, int end) {
        for (auto si = s.begin(), ei = e.begin();
             si != s.end() && ei != e.end(); si = next(si), ei = next(ei)) {
            if (start > *si) {
                if (start >= *ei) {
                    if (next(si) != s.end()) {
                        if (start >= *next(ei)) {
                            continue;
                        }
                        if (end <= *next(si)) {
                            return insert(start, end);
                        } else {
                            return false;
                        }
                    } else {
                        return insert(start, end);
                    }
                } else {
                    return false;
                }
            } else {
                if (end <= *si) {
                    return insert(start, end);
                } else {
                    return false;
                }
            }
        }
        return insert(start, end);
    }
};

// int main(int argc, const char** argv) {
//     std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

//     MyCalendar* obj = new MyCalendar();

//     vector<vector<int>> v({{23, 32}, {42, 50}, {6, 14},  {0, 7},   {21,
//     30},
//                            {26, 31}, {46, 50}, {28, 36}, {0, 6},   {27,
//                            36}, {6, 11},  {20, 25}, {32, 37}, {14, 20}, {7,
//                            16}, {13, 22}, {39, 47}, {37, 46}, {42, 50}, {9,
//                            17}, {49, 50}, {31, 37}, {43, 49}, {2, 10},  {3,
//                            12}, {8, 14},  {14, 21}, {42, 47}, {43, 49},
//                            {36, 43}});

//     for (size_t i = 0; i < v.size(); i++)
//         cout << obj->book(v[i][0], v[i][1]) << endl;

//     return 0;
// }
