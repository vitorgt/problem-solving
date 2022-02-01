class Solution {
  public:
    int openLock(vector<string> &deadends, string target) {
        unordered_set<string> dead_ends(deadends.begin(), deadends.end());

        if (dead_ends.count("0000"))
            return -1;

        queue<string> q({"0000"});

        for (int level = 0; !q.empty(); level++) {
            for (int levelSize = q.size(); levelSize > 0; levelSize--) {
                string curr = q.front();
                q.pop();

                if (curr == target)
                    return level;

                // insert possible moves in queue
                for (int i = 0; i < 4; i++) {
                    for (int diff = -1; diff <= 1; diff += 2) {
                        string neighbor = curr;
                        neighbor[i] =
                            (neighbor[i] - '0' + diff + 10) % 10 + '0';
                        if (dead_ends.count(neighbor))
                            continue;
                        dead_ends.insert(neighbor); // mark as visited
                        q.push(neighbor);
                    }
                }
            }
        }

        return -1;
    }
};
