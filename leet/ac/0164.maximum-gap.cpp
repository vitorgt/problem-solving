class SolutionA {
  public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        sort(nums.begin(), nums.end());

        int gap = 0;

        for (size_t i = 0; i < nums.size() - 1; i++)
            if (nums[i + 1] - nums[i] > gap) gap = nums[i + 1] - nums[i];

        return gap;
    }
};

class SolutionB {
  public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        int hi = nums[0], lo = nums[0];
        for (int n : nums) hi = max(hi, n), lo = min(lo, n);

        int bsize = max(int((hi - lo) / (nums.size() - 1)), 1);
        int nbuckets = (hi - lo) / bsize + 1;

        // first: smallest, second: biggest of a bucket
        unordered_map<int, pair<int, int>> buckets;

        int bucket = 0, hiB = 0, loB = 0;
        for (int n : nums) {
            bucket = (n - lo) / bsize;
            if (buckets.find(bucket) != buckets.end()) {
                loB = min(n, buckets[bucket].first);
                hiB = max(n, buckets[bucket].second);
                buckets[bucket] = make_pair(loB, hiB);
            } else {
                buckets[bucket] = make_pair(n, n);
            }
        }

        int gap = 0;

        for (size_t i = 0, j = 1; i < nbuckets - 1 && j < nbuckets; j++) {
            while (buckets.find(j) == buckets.end() && j < nbuckets) j++;
            if (j == bsize && buckets.find(j) == buckets.end()) break;
            gap = max(buckets[j].first - buckets[i].second, gap);
            i = j;
        }

        return gap;
    }
};
