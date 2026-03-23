#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node (int d) {
        data = d;
        next = NULL;
    }
};

Node* swapPairs(Node* head) {
    if (head == NULL || head->next == NULL) return head;

    Node* curr = head->next->next;
    Node* prev = head;
    head = head->next;
    head->next = prev;
    while (curr != NULL && curr->next != NULL) {
        prev->next = curr->next;
        prev = curr;
        Node* next = curr->next->next;
        curr->next->next = curr;
        curr = next;
    }
    prev->next = curr;
    return head;
}

int main() {
    Node* head = NULL;
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    swapPairs(head); // theta(n)
    return 0;
}