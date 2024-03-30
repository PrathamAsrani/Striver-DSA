#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        TrieNode *children[26];
        bool isEndOfWord = false;
};

class Trie{
    private:
        TrieNode *root;
    public:
        Trie(){
            root = new TrieNode();
        }

        void insert(string s){
            TrieNode *node = root;
            for(char c: s){
                if(node->children[c-'a'] == nullptr){
                    node->children[c-'a'] = new TrieNode();
                }
                node = node->children[c-'a'];
            }
            node->isEndOfWord = true;
        }

        bool search(string s){
            TrieNode *node = root;
            for(char c: s){
                if(node->children[c-'a'] == nullptr) return false;
                node = node->children[c-'a'];
            }
            return node->isEndOfWord;
        }

        bool startWith(string  prefix){
            TrieNode *node = root;
            for(char c: prefix){
                if(node->children[c-'a'] == nullptr) return false;
                node = node->children[c-'a'];
            }
            return true;
        }
};

int main(int argc, char const *argv[])
{
    Trie *trie = new Trie();
    trie->insert("Hello");
    trie->insert("World");
    cout << trie->search("Hello") << "\n";
    return 0;
}
