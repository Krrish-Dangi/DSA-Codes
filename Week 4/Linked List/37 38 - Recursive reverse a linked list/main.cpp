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


// Method 1

// Node* Reverse(Node* head) {
//     if (head == NULL) {
//         return NULL;
//     }
//     if (head->next == NULL) {
//         return head;
//     }
//     Node* rest_head =  Reverse(head->next);
//     Node* rest_tail = head->next;
//     rest_tail->next = head;
//     head->next = NULL;
//     return rest_head;
// }

// Method 2

Node* Reverse(Node* curr, Node* prev = NULL) {
    if (curr == NULL) {
        return prev;
    }

    Node* NEXT = curr->next;
    curr->next = prev;
    return Reverse(NEXT, curr);
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    print(head);
    head = Reverse(head);
    cout << endl;
    print(head);
    return 0;
}