#include <algorithm>
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* reverseLinkedList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    while (curr != NULL) {
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    }
    return prev->prev;
}

int main() {
    Node* head = NULL;
    head = new Node(1);
    head -> next = new Node(2);
    head -> next -> prev = head;
    head -> next -> next = new Node(3);
    head -> next -> next -> prev = head;
    head = reverseLinkedList(head); // theta(n)

    return 0;
}