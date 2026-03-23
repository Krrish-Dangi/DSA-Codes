#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node* insert(Node* head, int x) {
    Node* newNode = new Node(x);
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head = insert(head, 4);
}