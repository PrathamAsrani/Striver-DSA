//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    void inOrder(Node *root, vector<int> &arr){
        if(root){
            inOrder(root->left, arr);
            arr.push_back(root->data);
            inOrder(root->right, arr);
        }
    }
    vector<int> inOrder(Node* root) {
        /*
        // Technique 1
        vector<int> i;
        inOrder(root, i);
        return i;
        */
        
        /*
        // Technique 2
        vector<int> i;
        if(!root) return i;
        stack<Node*> st;
        Node* curr = root;
        while(!st.empty() || curr){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            i.push_back(curr->data);
            curr = curr->right;
        }
        return i;
        */
        
        // Technique 3
        vector<int> i;
        if(!root) return i;
        queue<Node *> q;
        Node *curr = root;
        while(curr){
            if(curr->left == nullptr){
                i.push_back(curr->data);
                curr = curr->right;
            }else{
                Node *predessor = curr->left;
                while(predessor->right && predessor->right != curr) predessor = predessor->right;
                if(predessor->right == nullptr){
                    predessor->right = curr;
                    curr = curr->left;
                }else{
                    predessor->right = nullptr;
                    i.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        return i;
    }
};

//{ Driver Code Starts.

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        Solution ob;
        vector<int> res = ob.inOrder(root);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends