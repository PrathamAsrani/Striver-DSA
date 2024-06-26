//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
int kthAncestor(Node *root, int k, int node);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k , node;
        scanf("%d ",&k);
        scanf("%d ",&node);
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		cout<<kthAncestor(root,k,node)<<endl;
    }
    return 0;
}

// } Driver Code Ends


//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
/*
int recursion(Node *root, int k, int node, int *val){
    if(root == NULL) return -1;
    if(root->data == node) return 0;
    int leftFind = recursion(root->left, k, node, val);
    int rightFind = recursion(root->right, k, node, val);
    if(leftFind != -1 && rightFind == -1) return (leftFind+1 == k)? (*val = root->data):leftFind+1;
    else if(leftFind == -1 && rightFind != -1) return (rightFind+1 == k)? (*val = root->data):rightFind+1;
    return -1;
}
*/

Node* recursion(Node *root, int &k, int &node);

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    /*
    int val = -1;
    recursion(root, k, node, &val);
    return val;
    */
    Node *parent = recursion(root, k, node);
    if(parent) return parent->data;
    else return -1;
}

Node* recursion(Node *root, int &k, int &node){
    if(!root) return 0;
    Node *returnValue = NULL;
    // preorder traversal
    if((root->data == node) || (returnValue = recursion(root->left, k, node)) || (returnValue = recursion(root->right, k, node))){
        if(k == 0) return root;
        k--;
        return (returnValue != NULL) ? returnValue:root; // IF returnValue != NULL 
    }
}



