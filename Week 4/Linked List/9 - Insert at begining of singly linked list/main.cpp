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

Node* pushInFront(Node *head, int x) {
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

void print(Node * head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head -> next;
    }
}

int main() {
    Node *head = NULL;
    head = pushInFront(head, 0);
    head = pushInFront(head, 1);
    head = pushInFront(head, 2);
    head = pushInFront(head, 3);
    head = pushInFront(head, 4);
    print(head);
    return 0;
}