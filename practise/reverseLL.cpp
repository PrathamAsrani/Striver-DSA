#include <bits/stdc++.h>

class Node
{
private:
    int data;
public:
    Node *link;
    Node();
    Node(int k){
        data = k;
        link = NULL;
    }
};

int main(int argc, char const *argv[])
{

    /*
    take three ptrs
    prev = NULL, next = NULL, curr = HEAD
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
    */    
    return 0;
}
