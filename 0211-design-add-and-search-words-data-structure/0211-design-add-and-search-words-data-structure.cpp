class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }

    bool contains(char ch) {
        return children[ch - 'a'] != nullptr;
    }

    TrieNode* get(char ch) {
        return children[ch - 'a'];
    }

    void put(char ch) {
        children[ch - 'a'] = new TrieNode();
    }

    void markEnd() {
        isEnd = true;
    }

    bool isWordEnd() {
        return isEnd;
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool dfs(TrieNode* node, string& word, int index) {
        if (node == nullptr)
            return false;

        if (index == word.size())
            return node->isWordEnd();

        char ch = word[index];

        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (dfs(node->children[i], word, index + 1))
                    return true;
            }
            return false;
        }

        return dfs(node->get(ch), word, index + 1);
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            if (!node->contains(ch))
                node->put(ch);

            node = node->get(ch);
        }

        node->markEnd();
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};