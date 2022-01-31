class Solution {
  private:
    class Node {
      public:
        string word;
        vector<Node *> adj;
        Node(string word) : word(word){};
        ~Node(){};
    };

  public:
    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<Node *> q;
        Node root(beginWord);
        Node *aux = NULL;
        q.push(&root);
        string buff;
        auto f = s.find("");
        int levelSize = 1, count = 0;
        while (!q.empty()) {
            levelSize = q.size();
            count++;
            while (levelSize--) {
                aux = q.front();
                buff = aux->word;
                for (int i = 0; i < buff.size(); i++) {
                    buff = aux->word;
                    for (int j = 0; j < 26; j++) {
                        buff[i] = j + 'a';
                        f = s.find(buff);
                        if (f != s.end()) {
                            if (*f == endWord) {
                                return count + 1;
                            }
                            aux->adj.push_back(new Node(*f));
                            s.erase(f);
                        }
                    }
                }
                for (auto e : aux->adj) {
                    q.push(e);
                }
                q.pop();
            }
        }
        return 0;
    }
};
