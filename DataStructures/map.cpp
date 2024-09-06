#include <bits/stdc++.h>

using namespace std;

template <typename Key, typename Value>
class Map
{
private:
    class Node
    {
    public:
        Key key;
        Value value;
        Node *left;
        Node *right;
        Node(Key k, Value v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };

    Node *root;

    Node *insert(Node *node, const Key &key)
    {
        if (node == nullptr)
        {
            return new Node(key, Value()); 
        }
        else if (key < node->key)
        {
            node->left = insert(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = insert(node->right, key);
        }
        return node;
    }

    Node *find(Node *node, const Key &key)
    {
        if (node == nullptr || node->key == key)
        {
            return node;
        }

        if (key < node->key)
        {
            return find(node->left, key);
        }
        else
        {
            return find(node->right, key);
        }
    }

    void inorderTraversal(Node *node) const
    {
        if (node == nullptr)
            return;
        inorderTraversal(node->left);
        cout << node->key << " : " << node->value << "\n";
        inorderTraversal(node->right);
    }

    void deleteTree(Node *node)
    {
        if (node == nullptr)
            return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    Map() : root(nullptr) {}

    ~Map()
    {
        deleteTree(root);
    }

    Value &operator[](const Key &key)
    {
        Node *node = find(root, key);
        if (node == nullptr)
        {
            root = insert(root, key);
            node = find(root, key);
        }
        return node->value;
    }

    void print()
    {
        inorderTraversal(root);
    }
};

int main()
{
    Map<int, int> mp;
    vector<int> arr = {1, 2, 3};
    for (auto &x : arr)
        mp[x]++;
    mp.print();
}