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

Node* insertAtEnd(Node* head, int x) {
    Node* newNode = new Node(x);
    if (newNode == NULL) {
        newNode->next = newNode;
        return newNode;
    }else {
        newNode->next = head->next;
        head->next = newNode;
        int t = head->data;
        head->data = newNode->data;
        newNode->data = t;
        return newNode;
    }
}

void printList(Node* head) {
    cout << head->data << " ";
    Node* curr = head->next;
    while (curr != head) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main() {
    Node* head = NULL;
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head;
    printList(head);
    cout << endl;
    head = insertAtEnd(head, 4);
    printList(head);
    return 0;
}