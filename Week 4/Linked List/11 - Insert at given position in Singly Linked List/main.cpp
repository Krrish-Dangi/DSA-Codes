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

Node* insert(Node *head, int pos, int data) {
    Node* newNode = new Node(data);
    if (pos == 1) {
        newNode->next = head;
        return newNode;
    }

    Node* curr = head;
    for (int i = 1; i <= pos-2 && curr != NULL; i++) {
        curr = curr->next;
    }

    if (curr == NULL) return head; // position out of range

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = insert(head, 4, 6);
    printList(head);

    return 0;
}
