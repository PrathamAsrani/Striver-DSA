#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data, height;
	struct Node *left, *right;
};

int max(int a, int b);
int DepthTree(struct Node *root);
int HeightNode(struct Node *root);
struct Node *createAVL_Node(int data);
int getBalanceFactor(struct Node *root);
struct Node *leftRotate(struct Node *root);
struct Node *rightRotate(struct Node *root);
struct Node *addNode(struct Node *root, int data);
void inOrder(struct Node *root);
int findPredecessor(struct Node *root);

int main()
{
	struct Node *root = addNode(root, 1);
	addNode(root, 2);
	addNode(root, 3);
	addNode(root, 4);
	addNode(root, 5);
	inOrder(root);
	printf("\n");
}

int max(int a, int b) { return (a > b) ? a : b; }

int HeightNode(struct Node *root)
{
	if (root == NULL)
		return 0;
	return root->height;
}

int DepthTree(struct Node *root)
{
	if (root == NULL)
		return 0;
	return max(DepthTree(root->left), DepthTree(root->right)) + 1;
}

struct Node *createAVL_Node(int data)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	if (newNode == NULL)
	{
		printf("Allocation Failed\n");
		return NULL;
	}
	newNode->height = 1; // it's a leaf node
	newNode->data = data;
	newNode->right = NULL;
	newNode->left = NULL;
	return newNode;
}

int getBalanceFactor(struct Node *root)
{
	if (root == NULL)
		return 0;
	return (HeightNode(root->left) - HeightNode(root->right));
}

struct Node *leftRotate(struct Node *root)
{
	struct Node *rightNode = root->right;
	struct Node *rightsLeftNode = rightNode->left;
	root->right = rightsLeftNode;
	rightNode->left = root;
	root->height = DepthTree(root);
	rightNode->height = DepthTree(rightNode);
	return rightNode;
}

struct Node *rightRotate(struct Node *root)
{
	struct Node *leftNode = root->left;
	struct Node *leftsRightNode = leftNode->right;
	root->left = leftsRightNode;
	leftNode->right = root;
	root->height = DepthTree(root);
	leftNode->height = DepthTree(leftNode);
	return leftNode;
}



struct Node *addNode(struct Node *root, int data)
{
	struct Node *newNode = createAVL_Node(data);
	if (root == NULL)
	{
		return newNode;
	}
	else if (data < root->data)
	{
		root->left = addNode(root->left, data);
		return root;
	}
	else if (data > root->data)
	{
		root->right = addNode(root->right, data);
		return root;
	}
	else
	{
		printf("Key already Present\n");
		return NULL;
	}
	root->height = DepthTree(root);
	// after adding
	int bf = getBalanceFactor(root);
	// ll
	if (bf > 1 && data < root->left->data)
	{
		// bf 1 means Left subtree is heavy, and root->left->data > data means the data is added to the left subtree of left side therefore ll case.
		rightRotate(root);
	}
	// rr
	else if (bf < -1 && data > root->right->data)
	{
		// bf 1 means Right subtree is heavy, and root->right->data < data means the data is added to the right subtree of right side therefore rr case.
		leftRotate(root);
	}
	// lr
	else if (bf > 1 && data > root->left->data)
	{
		root->left = leftRotate(root->left);
		rightRotate(root);
	}
	// rl
	else if (bf < -1 && data < root->right->data)
	{
		root->right = rightRotate(root->right);
		leftRotate(root);
	}
	return root;
}

void inOrder(struct Node *root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		printf("data: %d, \tThe BF: %d\n", root->data, getBalanceFactor(root));
		inOrder(root->right);
	}
}

int findPredecessor(struct Node *root)
{
	if (!root)
		return -1;
	while (root->left)
		root = root->left;
	return root->data;
}
