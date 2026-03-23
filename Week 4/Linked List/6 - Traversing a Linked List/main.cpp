#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node (int x) {
        data = x;
        next = NULL;
    }
};

void print(Node *head) { // this head and caller head has same address but is not same *****************
    Node *p = head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    print(head);
}