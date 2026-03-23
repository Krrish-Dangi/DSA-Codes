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

Node* Naive(Node* head, int x) {
    Node* temp = new Node(x);
    if (head == NULL) {
        temp->next = temp;
    }else {
        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
        temp->next = head;
    }
    return temp;
}

Node* best(Node* head, int x) {
    Node* temp = new Node(x);
    if (head == NULL) {
        temp->next = temp;
        return temp;
    }else {
        temp->next = head->next;
        head->next = temp;
        int t = head->data;
        head->data = temp->data;
        temp->data = t;
        return head;
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
    // head = Naive(head, 0); // O(n)
    head = best(head,-1); // O(1)
    printList(head);
}