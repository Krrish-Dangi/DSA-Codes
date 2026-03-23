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

void detectAndRemoveLoop(Node* head) {
    Node* slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }

    if (slow != fast) {
        return;
    }

    slow = head;
    while (slow->next != fast->next) { // why next? => we want hold on last node too
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}

int main() {
    Node* head = NULL;
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head;


}