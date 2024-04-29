#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        long long int data;
        Node *left, *right;
        Node(){
            data = 0;
            left = right = nullptr;
        }
        Node(int d){
            data = d;
            left = right = nullptr;
        }
};

Node *buildTree(int node, vector<long long int> &arr){
    if(node >= arr.size()) return nullptr;
    Node *root = new Node(arr[node]);
    root->left = buildTree(2*node + 1, arr);
    root->right = buildTree(2*node + 2, arr);
    return root;
}

bool helper(Node *left, Node *right){
    if(!left && !right) return true;
    if(!left || !right || left->data != right->data) return false;
    
    return helper(left->left, right->right) && helper(left->right, right->left);
}
bool isSymmetric(Node* root) {
    if(!root) return true;
    return helper(root->left, root->right);
}

void helper(string s){
    stringstream ss(s);
    string word;
    vector<string> v;
    int cnt = 0;
    while(getline(ss, word, ' ')){
        // cout << word << "\n";
        v.push_back(word);
        cnt++;
    }
    vector<long long int> arr;
    for(auto x: v){
        arr.push_back(stoll(x));
    }
    Node *root = new Node(arr[0]);
    root->left = buildTree(2*0+1, arr);
    root->right = buildTree(2*0+2, arr);

    cout <<"cnt: " << cnt << "\n";
    cout << isSymmetric(root);
}


int main(){
    string s = "1 2 2 3 4 4 3";

    helper(s);
}