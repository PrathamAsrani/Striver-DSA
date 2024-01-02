#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    node *createNode(int data)
    {
        node *newNode = new node(data);
        if (newNode == NULL)
        {
            cout << "Allocation failed in CreateNode Method\n";
            return NULL;
        }
        newNode->right = newNode->left = NULL;
        return newNode;
    }

    node *addNode(node *root, int data)
    {
        node *newNode = new node(data);
        if (root == NULL)
        {
            root = newNode;
            return root;
        }
        else if (data < root->data)
        {
            root->left = root->addNode(root->left, data);
            return root;
        }
        else if (data > root->data)
        {
            root->right = root->addNode(root->right, data);
            return root;
        }
        else
        {
            // same value
            cout << "Value already in the tree\n";
            return NULL;
        }
    }

    node *removeData(node *root, int data)
    {
        if (root == NULL)
        {
            cout << "Data not found\n";
            return NULL;
        }
        else if (data < root->data)
        {
            root->left = root->removeData(root->left, data);
            return root;
        }
        else if (data > root->data)
        {
            root->right = root->removeData(root->right, data);
            return root;
        }
        else
        {
            free(root);
            return NULL;
        }
    }

    void Inorder(node *root);
    void Preorder(node *root);
    void Postorder(node *root);
    int heightBST(node *root);
};

int node::heightBST(node *root){
    if(root == NULL){
        return 0;
    }
    return max(heightBST(root->left), heightBST(root->right)) + 1;
}

void node::Inorder(node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}

void node::Preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

void node::Postorder(node *root)
{
    if (root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    node *root = new node(10);
    cout << "\nInorder traveral used to check whether a tree is BST or not\n\nAdding Nodes\n";
    root->addNode(root, 5);
    root->addNode(root, 7);
    root->addNode(root, 3);
    root->addNode(root, 9);
    root->addNode(root, 11);
    root->addNode(root, 15);
    root->addNode(root, 14);
    root->addNode(root, 13);
    root->addNode(root, 12);
    root->addNode(root, 18);
    cout << "Inorder Traversal: ";
    root->Inorder(root);
    cout << "\n";
    cout << "Preorder Traversal: ";
    root->Preorder(root);
    cout << "\n";
    cout << "Postorder Traversal: ";
    root->Postorder(root);
    cout << "\n";

    cout << "\nRemoving Node (Note we can't remove the root node(here it's the 10))\n"
         << "Enter value: ";
    int data;
    cin >> data;
    root->removeData(root, data);
    cout << "\nAfter removing: \nInoreder Traversal: ";
    root->Inorder(root);
    cout << "\n\nHeigth of BST: ";
    cout << (root->heightBST(root));
    cout << "\n\n";
}