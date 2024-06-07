#include <bits/stdc++.h>
using namespace std;
// leetcode 648

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    string word = "";
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->word = word;
    }

    string findRoot(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return word;
            }
            node = node->children[ch];
            if (!node->word.empty()) {
                return node->word;
            }
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (const string& root : dictionary) {
            trie.insert(root);
        }

        stringstream ss(sentence);
        string word;
        string result;
        bool firstWord = true;

        while (ss >> word) {
            if (!firstWord) {
                result += " ";
            }
            firstWord = false;
            result += trie.findRoot(word);
        }

        return result;
    }
};

// Example usage
int main() {
    Solution solution;
    vector<string> dictionary = {"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";
    string result = solution.replaceWords(dictionary, sentence);
    cout << result << endl; // Output: "the cat was rat by the bat"
    return 0;
}
