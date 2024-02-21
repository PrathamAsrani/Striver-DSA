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
            TrieNode* node = root;
            for(char c : s){
                if(node->children[c - 'a'] == nullptr){
                    node->children[c - 'a'] = new TrieNode();
                }
                node = node->children[c - 'a'];
            }
            node->isEndOfWord = true;
        }
        bool search(string s){
            TrieNode *node = root;
            for(char c : s){
                if(node->children[c-'a'] == nullptr) return false;
                node = node->children[c-'a'];
            }
            return node->isEndOfWord;
        }
};

int main(){

}