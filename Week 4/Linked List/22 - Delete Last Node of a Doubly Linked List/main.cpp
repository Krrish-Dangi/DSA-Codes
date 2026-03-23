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

Node* deleteTail(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->prev->next = NULL;
    delete curr;
    return head;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    cout << "Original list: ";
    printList(head);

    head = deleteTail(head);

    cout << "After deleting tail: ";
    printList(head);

    return 0;
}
