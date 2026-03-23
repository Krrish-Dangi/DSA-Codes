#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

int main() {
    // Simple Way
    Node* head = new Node(1);
    Node* temp = new Node(2);
    head->next = temp;
    temp->prev = head;
}