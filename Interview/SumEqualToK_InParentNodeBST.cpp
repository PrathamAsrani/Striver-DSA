#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr) {}
};

class BST {
public:
    Node* insert(Node* root, int key) {
        if(!root) return new Node(key);

        Node *curr = nullptr;
        if(key == root->data) {
            return nullptr;
        } else if (root->data > key) {
            curr = insert(root->left, key);
            if(!curr)
                return root;
            root->left = curr;
            curr->parent = root;
        } else {
            curr = insert(root->right, key);
            if(!curr)
                return root;
            root->right = curr;
            curr->parent = root;
        }
        
        return root;
    }

    Node* buildTree() {
        Node* root = nullptr;
        root = insert(root, 10);
        insert(root, 5);
        insert(root, 15);
        insert(root, 2);
        insert(root, 7);
        insert(root, 12);
        insert(root, 20);
        return root;
    }
};


class Solution {
public:
    bool isPairPresent(Node* root, int target) {
        Node* left = getSmallest(root);
        Node* right = getLargest(root);

        while (left != right && left->data < right->data) {
            int sum = left->data + right->data;
            if (sum == target) {
                return true;
            } else if (sum < target) {
                left = sucessor(left);
            } else {
                right = predecessor(right);
            }
        }

        return false;
    }

private:
    Node* getSmallest(Node* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    Node* getLargest(Node* node) {
        while (node && node->right) {
            node = node->right;
        }
        return node;
    }

    Node *successor(Node *node){
        if(node && node->right){
            return getSmallest(node->right);
        } else if (node) {
            while(node->parent && node->parent->right == node){
                node = node->parent;
            }
            return node->parent;
        }
    }

    Node *predecessor(Node *node) {
        if(node && node->left){
            return getLargest(node->left);
        } else if (node) {
            while(node->parent && node->parent->left == node){
                node = node->parent;
            }
            return node->parent;
        }
    }
};


int main() {
    BST bst;
    Node* root = bst.buildTree();
    
    Solution solution;
    int target = 22;

    if (solution.isPairPresent(root, target)) {
        cout << "Pair with sum " << target << " is present." << endl;
    } else {
        cout << "Pair with sum " << target << " is not present." << endl;
    }

    return 0;
}