#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteNode(int value) {
        // takes O(N)
        Node* current = head;
        while (current) {
            if (current->data == value) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                    if (head) {
                        head->prev = nullptr;
                    }
                }

                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                    if (tail) {
                        tail->next = nullptr;
                    }
                }

                delete current;
                return;
            }
            current = current->next;
        }

        std::cout << "Value not found in the list.\n";
    }

    void deleteNode(Node *node){
        // O(1)
        if(node == nullptr) return;
        if(node->prev){
            node->prev->next = node->next;
        }else{
            head = node->next;
            if(head) head->prev = nullptr;
        }
        if(node->next){
            node->next->prev = node->prev;
        }else{
            tail = node;
            if(tail) tail->next = nullptr;
        }
        delete node;
    }

    void deleteFromFront() {
        if (head) {
            Node* temp = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            delete temp;
        } else {
            std::cout << "List is empty. Nothing to delete from the front.\n";
        }
    }

    void deleteFromRear() {
        if (tail) {
            Node* temp = tail;
            tail = tail->prev;
            if (tail) {
                tail->next = nullptr;
            } else {
                head = nullptr;
            }
            delete temp;
        } else {
            std::cout << "List is empty. Nothing to delete from the rear.\n";
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

    void traverseFromLast() {
        Node* current = tail;
        while (current) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << "\n";
    }
};

int main() {
    DoublyLinkedList myList;

    myList.insertAtEnd(1);
    myList.insertAtEnd(2);
    myList.insertAtEnd(3);

    std::cout << "Original List: ";
    myList.display();

    myList.insertAtBeginning(0);
    myList.insertAtEnd(4);

    std::cout << "After Insertion: ";
    myList.display();

    myList.deleteNode(2);

    std::cout << "After Deletion: ";
    myList.display();

    std::cout << "Traverse from last to first: ";
    myList.traverseFromLast();

    return 0;
}
