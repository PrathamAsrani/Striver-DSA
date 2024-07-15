// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr), parent(nullptr) {}
};

class BST {
public:
    TreeNode* insert(TreeNode* root, int key) {
        if (!root) return new TreeNode(key);

        TreeNode* current;
        if (key < root->val) {
            current = insert(root->left, key);
            root->left = current;
            current->parent = root;
        } else {
            current = insert(root->right, key);
            root->right = current;
            current->parent = root;
        }
        return root;
    }

    TreeNode* buildTree() {
        TreeNode* root = nullptr;
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
    // -------------------- approach 1 --------------------
    TreeNode *smallest(TreeNode *root){
        while(root && root->left) root = root->left;
        return root;
    }
    TreeNode *largest(TreeNode *root){
        while(root && root->right) root = root->right;
        return root;
    }
    
    TreeNode *succ = nullptr;
    TreeNode *successor(TreeNode *root, TreeNode *x){
        if(!root) return succ;
        if(root->val > x->val) {
            succ = root;
            return successor(root->left, x);
        } else {
            return successor(root->right, x);
        }
        return succ;
    }

    TreeNode *pred = nullptr;
    TreeNode *predecessor(TreeNode *root, TreeNode *x){
        if(!root) return pred;
        if(root->val < x->val){
            pred = root;
            return predecessor(root->right, x);
        } else{
            return predecessor(root->left, x);
        }
        return pred;
    }

    // -------------------- approach 2 --------------------
    unordered_map<int, int> umpp;

    // -------------------- approach 3 --------------------
    bool find(TreeNode* selected, TreeNode* curr, int x){
        if(!curr) return false;

        while(curr){
            if(curr->val == x && curr != selected){
                return 1;
            } else if (curr->val > x) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        
        return false;
    }

    bool fun(TreeNode* curr, TreeNode* root, int k){
        if(!curr) return 0;

        int rem = k - curr->val;
        if(find(curr, root, rem))
            return 1;

        if(fun(curr->left, root, k))
            return 1;
        return fun(curr->right, root, k);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        /*
        // approach 1: 
        // TC: O(H * H)
        // SC: O(1)

        if(!root) return false;
        TreeNode *left = smallest(root);
        TreeNode *right = largest(root);

        while(left != right){
            int sum = left->val + right->val;
            if(sum == k) {
                return 1;
            } else if (sum > k){
                right = predecessor(root, right);
            } else {
                left = successor(root, left);
            }
        }
        return 0;
        */

        /*
        // approach 2: 
        // TC: O(H)
        // SC: O(N)
        if(!root) return 0;
        if(umpp.find(root->val) != umpp.end()){
            return 1;
        }
        umpp[k - root->val]++;
        if(findTarget(root->left, k)) return 1;
        return findTarget(root->right, k);
        */

        // approach 3:
        // TC: O(H * H), H: height of the tree
        // SC: O(1)
        return fun(root, root, k);
    }
};

int main() {
    BST bst;
    TreeNode* root = bst.buildTree();

    Solution solution;
    int target = 22;

    if (solution.findTarget(root, target)) {
        cout << "Pair with sum " << target << " is present." << endl;
    } else {
        cout << "Pair with sum " << target << " is not present." << endl;
    }

    return 0;
}