#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(){
            data = 0;
            next = nullptr;
        }
        Node(int x){
            data = x;
            next = nullptr;
        }
};

void display(Node *head);
Node *mergeLL(Node *head1, Node *head2);

int main(){
    Node *head1 = new Node(10);
    Node *ptr = head1;
    for(int i = 11; i < 13; i++){
        ptr->next = new Node(i+5);
        ptr = ptr->next;
    }
    Node *head2 = new Node(11);
    ptr = head2;
    for(int i = 12; i < 16; i++){
        ptr->next = new Node(i+2);
        ptr = ptr->next;
    }
    display(head1);
    display(head2);

    cout << "merge linked list without extra space\n";
    Node *head = mergeLL(head1, head2);
    display(head);
}

void display(Node *head){
    Node *ptr = head;
    cout << "List: ";
    while(ptr){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << "\n";
}

Node *mergeLL(Node *head1, Node *head2){
    if(!head1) return head2;
    if(!head2) return head1;
    Node *tmp = nullptr;
    if(head1->data < head2->data){
        tmp = head1;
        head1->next = mergeLL(head1->next, head2);
    }else{
        tmp = head2;
        head2->next = mergeLL(head1, head2->next);
    }
    return tmp;
}