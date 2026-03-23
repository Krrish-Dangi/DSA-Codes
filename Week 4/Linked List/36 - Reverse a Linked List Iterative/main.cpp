#include <algorithm>
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* Reverse(Node* head) {
    Node* current = head;
    Node* prev = NULL;
    while (current != NULL) {
        Node* temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    return prev;
}

int main() {
    Node* head = NULL;
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head = Reverse(head);
    return 0;
}