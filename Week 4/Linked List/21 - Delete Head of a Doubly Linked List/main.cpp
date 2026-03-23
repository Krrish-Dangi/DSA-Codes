#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node* deleteHead(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
    Node* temp = head;
    head->next->prev = NULL;
    delete head;
    return temp->next;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head = deleteHead(head);
    return 0;
}