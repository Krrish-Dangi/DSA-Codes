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

Node* Naive(Node* head) {
    if (head == NULL) {
        return NULL;
    }else if (head->next == head) {
        delete head;
        return NULL;
    }else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        delete head;
        return temp->next;
    }
}

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

void printList(Node* head) {
    if (head == NULL) {
        cout << " "<< endl;
        return;
    }else {
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        }while (temp != head);
    }
}

int main() {
    Node* head = NULL;
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head;
    // head = Naive(head); // theta(n)
    head = deleteHead(head); // theta(1)
    printList(head);
    return 0;
}