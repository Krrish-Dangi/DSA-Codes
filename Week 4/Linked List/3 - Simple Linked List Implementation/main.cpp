#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

int main() {
    // Implementation - 1
    Node *head = new Node(1);
    Node *temp1 = new Node(2);
    Node *temp2 = new Node(3);
    head->next = temp1;
    temp1->next = temp2;

    // Implementation - 2 (Shorter)
    Node * head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    return 0;
}