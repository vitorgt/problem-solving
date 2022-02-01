/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class Trie {
  private:
    class Node {
      public:
        bool val;
        vector<Node *> az;
        Node() : val(false), az(26, NULL) {}
        Node(bool x) : val(x), az(26, NULL) {}
    };
    Node *root = NULL;

  public:
    /** Initialize your data structure here. */
    Trie() { root = new Node(); }

    /** Inserts a word into the trie. */
    void insert(string word) {
        const int n = word.length();
        Node *aux = root;
        for (int i = 0; i < n; i++) {
            if (!aux->az[word[i] - 'a']) {
                aux->az[word[i] - 'a'] = new Node();
            }
            aux = aux->az[word[i] - 'a'];
        }
        aux->val = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        const int n = word.length();
        Node *aux = root;
        for (int i = 0; i < n; i++) {
            if (!aux->az[word[i] - 'a']) {
                return false;
            }
            aux = aux->az[word[i] - 'a'];
        }
        return aux->val;
    }

    /** Returns if there is any word in the trie that starts with
     * the given prefix. */
    bool startsWith(string prefix) {
        const int n = prefix.length();
        Node *aux = root;
        for (int i = 0; i < n; i++) {
            if (!aux->az[prefix[i] - 'a']) {
                return false;
            }
            aux = aux->az[prefix[i] - 'a'];
        }
        return true;
    }
};
