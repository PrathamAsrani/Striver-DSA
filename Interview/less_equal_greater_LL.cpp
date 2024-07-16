#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};
void printList(Node *head)
{
    Node *curr_node = head;
    while (curr_node != NULL)
    {
        if (curr_node->next == NULL)
        {
            cout << curr_node->data << " ";
        }
        else
        {
            cout << curr_node->data << " -> ";
        }
        curr_node = curr_node->next;
    }
    cout << endl;
}
Node *partition(Node *head, int x)
{
    Node *less = NULL;
    Node *less_last = NULL;
    Node *equal = NULL;
    Node *equal_last = NULL;
    Node *greater = NULL;
    Node *greater_last = NULL;
    Node *curr_node = head;
    while (curr_node != NULL)
    {
        if (curr_node->data < x)
        {
            if (less == NULL)
            {
                less = new Node(curr_node->data);
                less_last = less;
            }
            else
            {
                less_last->next = new Node(curr_node->data);
                less_last = less_last->next;
            }
        }
        else if (curr_node->data == x)
        {
            if (equal == NULL)
            {
                equal = new Node(curr_node->data);
                equal_last = equal;
            }
            else
            {
                equal_last->next = new Node(curr_node->data);
                equal_last = equal_last->next;
            }
        }
        else
        {
            if (greater == NULL)
            {
                greater = new Node(curr_node->data);
                greater_last = greater;
            }
            else
            {
                greater_last->next = new Node(curr_node->data);
                greater_last = greater_last->next;
            }
        }
        curr_node = curr_node->next;
    }
    if (less == NULL)
    {
        if (equal == NULL)
            return greater;
        equal_last->next = greater;
        return equal;
    }
    if (equal == NULL)
    {
        less_last->next = greater;
        return less;
    }
    less_last->next = equal;
    equal_last->next = greater;
    return less;
}
Node* partitionConstantSpace(Node* head, int x) {
    if(!head) return head;

    Node *less_head = new Node(0);
    Node *equal_head = new Node(0);
    Node *great_head = new Node(0);

    Node *less = less_head, *equal = equal_head, *great = great_head;
    Node *curr = head;

    while(curr){
        if(curr->data < x) {
            less->next = curr;
            less = less->next;
        } else if (curr->data == x) {
            equal->next = curr;
            equal = equal->next;
        } else {
            great->next = curr;
            great = great->next;
        }
        curr = curr->next;
    }

    great->next = nullptr;
    equal->next = great_head->next;
    less->next = equal_head->next;

    Node *newHead = less_head->next;

    delete less_head;
    delete equal_head;
    delete great_head;

    return newHead;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(4);
    head->next->next = new Node(5);
    head->next->next->next = new Node(9);
    head->next->next->next->next = new Node(8);
    head->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next = new Node(2);
    cout << "The given linked list is: " << endl;
    printList(head);
    int x = 5;
    // head = partition(head, x);
    head = partitionConstantSpace(head, x);
    cout << "The linked list after partition is: " << endl;

    printList(head);
}