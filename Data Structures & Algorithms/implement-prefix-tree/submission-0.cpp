class Node {
private:
    Node* links[26];  // only lowercase a-z
    bool flag = false;

public:
    bool containsKey(char ch) {
        return (links[ch - 'a'] != nullptr);
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class PrefixTree {
private:
    Node* root;

public:
    PrefixTree() {
        root = new Node();
    }

    // Insert a word
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);  // ✅ move to next node
        }
        node->setEnd();  // mark end of word
    }

    // Search exact word
    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    // Search by prefix
    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {  // ✅ use prefix.length()
            if (!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

