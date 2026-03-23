#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;

    Node (int x) {
        data = x; next = NULL;
    }
};

Node* push_back(Node *head, int x) {
    Node *temp = new Node(x);
    if (head == NULL) {
        return temp;
    }
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = temp;
    return head;
}

void print(Node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node *head = NULL;
    head = push_back(head, 2);
    head = push_back(head, 3);
    head = push_back(head, 4);
    head = push_back(head, 5);
    head = push_back(head, 6);
    print(head);
}