#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *addr;
        Node (int d = -1, Node *ptr = NULL) : data(d) , addr(ptr) {}
};

class XORLinkedList{
    private:
        Node *head, *tail;
        Node *XOR(Node *a, Node *b);
    public:
        XORLinkedList();
        void insertAtHead(int data);
        void insertAtTail(int data);
        void deleteFromHead();
        void deleteFromTail();
        void printList();
};

XORLinkedList::XORLinkedList(){
    head = tail = NULL;
}

Node *XORLinkedList::XOR(Node *a, Node *b){
    return (Node *)((uintptr_t)(a) ^ (uintptr_t)(b));
}

void XORLinkedList::insertAtHead(int data){
    Node *node = new Node(data);
    node->addr = head;
    if(head){
        head->addr = XOR(node, head->addr);
    }
    else{
        tail = node;
    }
    head = node;
}

void XORLinkedList::insertAtTail(int data){
    Node *node = new Node(data);
    node->addr = tail;
    if(tail){
        tail->addr = XOR(node, tail->addr);
    }
    else{
        head = node;
    }
    tail = node;
}

void XORLinkedList::deleteFromHead(){
    if(head){
        Node *next = head->addr;
        delete head;
        head = next;

        if(next){
            next->addr = XOR(head, next->addr);
        }
        else{
            tail = NULL;
        }
    }
}

void XORLinkedList::deleteFromTail(){
    if(tail){
        Node *prev = tail->addr;
        delete tail;
        tail = prev;

        if(prev){
            prev->addr = XOR(prev->addr, tail);
        } else {
            head = NULL;
        }
    }
}

void XORLinkedList::printList(){
    cout << "\n1:forward printing\n2:backward printing\nEnter number: ";
    short choice;
    cin >> choice;
    Node *curr = head, *next = NULL, *prev = NULL;
    if(choice == 1){
        while(curr){
            cout << curr->data << " ";
            next = XOR(prev, curr->addr);
            prev = curr;
            curr = next;
        }
        cout << "\n";
    } else if(choice == 2){
        while(curr){
            cout << curr->data << " ";
            prev = XOR(next, curr->addr);
            next = curr;
            curr = prev;
        }
        cout << "\n";
    } else {
        cout << "Invalid choice\n\n";
    }
}

int main(){
    XORLinkedList list;
    list.insertAtHead(10);
    list.printList();
    list.insertAtTail(20);
    list.printList();
    list.insertAtHead(30);
    list.printList();
    list.insertAtTail(40);
    list.printList();
}