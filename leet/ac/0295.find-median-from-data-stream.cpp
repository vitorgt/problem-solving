class MedianFinder {
  private:
    map<int, int> count;
    int size;

  public:
    MedianFinder() { this->size = 0; }

    void addNum(int num) {
        this->count[num]++;
        this->size++;
    }

    double findMedian() {
        int n = floor(this->size / 2.0);
        int i = 0;
        auto it = this->count.begin();

        while (it != this->count.end() && i + it->second < n) {
            i += it->second;
            it = next(it);
        }

        if (i + it->second == n) {
            if (size % 2)
                return next(it)->first;
            return (it->first + next(it)->first) / 2.0;
        } else
            return it->first;
    }
};
