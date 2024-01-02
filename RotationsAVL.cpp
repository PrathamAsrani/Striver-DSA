// for c code check Code with harry DSA playlist
#include <bits/stdc++.h>

using namespace std;

class AVL_node
{
public:
    int data, height;
    AVL_node *left, *right;

    AVL_node *createNode(int key)
    {
        AVL_node *newNode = new AVL_node();
        if (newNode == NULL)
            return NULL;
        newNode->data = key;
        newNode->left = newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }

    AVL_node *rightRotate(AVL_node *imbalanceNode)
    {
        AVL_node *leftNode = imbalanceNode->left;
        AVL_node *left_right = leftNode->right;
        imbalanceNode->left = left_right;
        leftNode->right = imbalanceNode;
        imbalanceNode->height = Depth(imbalanceNode);
        leftNode->height = Depth(leftNode);
        left_right->height = Depth(left_right);
        return leftNode;
    }

    AVL_node *leftRotate(AVL_node *imbalanceNode)
    {
        AVL_node *rightNode = imbalanceNode->right;
        AVL_node *right_left = rightNode->left;
        imbalanceNode->right = right_left;
        rightNode->left = imbalanceNode;
        imbalanceNode->height = Depth(imbalanceNode);
        rightNode->height = Depth(rightNode);
        right_left->height = Depth(right_left);
        return rightNode;
    }

    AVL_node *insertNode(AVL_node *root, int key)
    {
        if (root == NULL)
            return createNode(key);
        if (key < root->data)
            root->left = insertNode(root->left, key);
        else if (key > root->data)
            root->right = insertNode(root->right, key);
        else if (key == root->data)
        {
            cout << "Data already present\n";
            return root;
        }
        root->height = Depth(root);
        int balanceFactor = getBalanceFactor(root);
        // left left case
        if (balanceFactor > 1 && key < root->left->data)
        {
            return rightRotate(root);
        }
        // right right case
        if (balanceFactor < -1 && key > root->right->data)
        {
            return leftRotate(root);
        }
        // left right case
        if (balanceFactor > 1 && key > root->left->data)
        {
            root->left = leftRotate(root);
            return rightRotate(root);
        }
        // right left case
        if (balanceFactor < -1 && key < root->right->data)
        {
            root->right = rightRotate(root);
            return leftRotate(root);
        }
        return root;
    }

    void Inorder(AVL_node *root);

    int Depth(AVL_node *root);
    int getBalanceFactor(AVL_node *root);
};

int main()
{
    AVL_node *root = NULL;
    root = root->insertNode(root, 1);
    root = root->insertNode(root, 2);
    // root = root->insertNode(root, 3);
    // root = root->insertNode(root, 5);
    // root = root->insertNode(root, 6);
    // root = root->insertNode(root, 3);
    root->Inorder(root);
    cout << "\n";
}

int AVL_node::Depth(AVL_node *root)
{
    if (root == NULL)
        return 0;
    return max(Depth(root->left), Depth(root->right)) + 1;
}

int AVL_node::getBalanceFactor(AVL_node *root)
{
    if (root == NULL)
        return 0;
    int leftTreeHeight = Depth(root->left);
    int rightTreeHeight = Depth(root->right);
    return rightTreeHeight - leftTreeHeight;
}

void AVL_node::Inorder(AVL_node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}