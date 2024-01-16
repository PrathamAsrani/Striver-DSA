#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    Node *mergeKLists(Node *arr[], int K)
    {
        // used compare class here
        priority_queue<Node *, vector<Node *>, compare> minHeap;

        for (int i = 0; i < K; i++)
        {
            if (arr[i] != NULL)
                minHeap.push(arr[i]);
        }

        Node *ans = new Node(-1);
        Node *temp = ans;

        while (minHeap.size() > 0)
        {
            Node *top = minHeap.top();
            minHeap.pop();

            if (top->next != NULL)
            {
                minHeap.push(top->next);
            }

            temp->next = top;
            temp = top;
        }

        return ans->next;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        struct Node *arr[N];
        for (int j = 0; j < N; j++)
        {
            int n;
            cin >> n;

            int x;
            cin >> x;
            arr[j] = new Node(x);
            Node *curr = arr[j];
            n--;

            for (int i = 0; i < n; i++)
            {
                cin >> x;
                Node *temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
        }
        Solution obj;
        Node *res = obj.mergeKLists(arr, N);
        printList(res);
    }

    return 0;
}
