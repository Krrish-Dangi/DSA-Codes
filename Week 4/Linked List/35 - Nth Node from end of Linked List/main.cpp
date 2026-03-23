#include <bits/stdc++.h>

using namespace std;
struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void Find(Node* head, int k) {
    if (head == NULL) {
        return;
    }
    Node* first = head;
    for (int i = 0; i < k; i++) {
        if (first == NULL) {
            return;
        }
        first = first->next;
    }
    Node* second = head;
    while (first != NULL) {
        second = second->next;
        first = first->next;
    }
    cout << second->data << " ";
}

int main() {
    Node *head = new Node(0);
    head -> next = new Node(1);
    head -> next -> next = new Node(2);
    head -> next -> next -> next = new Node(3);
    Find(head, 3); // O(n)
    return 0;
}
