#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }

};

Node* insert(Node* head, int d) {
    Node* temp = new Node(d);
    if (head == NULL) {
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }
    temp->prev = head->prev;
    temp->next = head;
    temp->prev->next = temp;
    head->prev = temp;
    return temp;
}

Node* insertAtEnd(Node* head, int d) {
    Node* temp = new Node(d);
    if (head == NULL) {
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }
    temp->prev = head->prev;
    temp->next = head;
    temp->prev->next = temp;
    head->prev = temp;
    return head;
}

int main(){
    Node* head = NULL;
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);
    head = insert(head, 50);
    head = insertAtEnd(head, 50);
    head = insertAtEnd(head, 60);
    return 0;
}