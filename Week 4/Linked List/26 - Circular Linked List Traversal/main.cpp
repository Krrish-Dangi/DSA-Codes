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

void printList(Node* head) {
    if (head == NULL) {
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    }while (temp != head);
}

int main() {
    Node* head = NULL;
    // printList(head);
    head = new Node(1);
    // head->next = head;
    // printList(head);
    // cout << endl;
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;
    printList(head);
    return 0;
}