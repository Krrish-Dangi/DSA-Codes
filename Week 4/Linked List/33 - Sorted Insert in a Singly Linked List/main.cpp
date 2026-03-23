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

Node *SortedInsert(Node *head, int x) {
    Node* temp = new Node(x);
    if (head == NULL) {
        return temp;
    }
    if (x < head->data) {
        temp->next = head;
        return temp;
    }
    Node* current = head;
    while (current->next != NULL && current->next->data < x) {
        current = current->next;
    }
    temp->next = current->next;
    current->next = temp;
    return head;
}

int main() {
    Node* head = NULL;
    head = SortedInsert(head, 10);
    head = SortedInsert(head, 20);
    head = SortedInsert(head, 30);
    head = SortedInsert(head, 40);
    return 0;
}