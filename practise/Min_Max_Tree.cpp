//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// } Driver Code Ends
class Solution
{
public:
    // Function to check whether a Binary Tree is BST or not.

    int maxValue(Node *root)
    {
        // find maximum of a tree
        if(root == NULL) return 0;
        int data = root->data;
        int leftData = maxValue(root->left);
        int rightData = maxValue(root->right);
        return max(data, max(leftData, rightData));
    }
    int minValue(Node *root)
    {
        // find minimun of a tree
        if(root == NULL) return 0;
        int data = root->data;
        int leftData = minValue(root->left);
        int rightData = minValue(root->right);
        return min(data, min(leftData, rightData));
    }

    bool isBST(Node *root)
    {
        // Your code here
        // check for the Degree and left and right root value
        if (root == NULL)
            return 1;

        /* false if the max of the left is > than us */
        if (root->left != NULL && maxValue(root->left) > root->data)
            return 0;

        /* false if the min of the right is <= than us */
        if (root->right != NULL && minValue(root->right) < root->data)
            return 0;

        /* false if, recursively, the left or right is not a BST
         */
        if (!isBST(root->left) || !isBST(root->right))
            return 0;

        /* passing all that, it's a BST */
        return 1;
    }
};

//{ Driver Code Starts.

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current root's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current root
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current root
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inorder(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main()
{

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution ob;
        if (ob.isBST(root))
            cout << "1\n";

        else
            cout << "0\n";
    }
    return 0;
}

// } Driver Code Ends