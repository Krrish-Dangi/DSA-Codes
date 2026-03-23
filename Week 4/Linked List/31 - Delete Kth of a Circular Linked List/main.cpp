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

Node* deleteHead(Node* head) {
    if (head == NULL) {
        return NULL;
    }else if (head->next == head) {
        delete head;
        return NULL;
    }else {
        head->data = head->next->data;
        Node* temp = head->next;
        head->next = head->next->next;
        delete temp;
        return head;

    }
}

Node* deleteKth(Node* head, int k) {
    if (head == NULL) {
        return NULL;
    }

    if (k == 1) {
        deleteHead(head);
    }else {
        Node* curr = head;
        for (int i = 0; i < k - 2; i++) {
            curr = curr->next;
        }
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        return head;
    }
}

int main() {
    Node* head = NULL;
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head;
    head = deleteKth(head, 2);
    return 0;
}