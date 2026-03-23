#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char x) {
        data = x;
        next = NULL;
    }
};

// Function to reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    // Find middle (slow will stop at middle)
    Node* slow = head;
    Node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    Node* rev = reverseList(slow->next);

    // Compare first half and reversed second half
    Node* curr = head;
    Node* temp = rev;
    while (temp != NULL) {
        if (curr->data != temp->data) {
            return false;
        }
        curr = curr->next;
        temp = temp->next;
    }

    return true;
}

int main() {
    Node* head = NULL;
    head = new Node('R');
    head->next = new Node('A');
    head->next->next = new Node('D');
    head->next->next->next = new Node('A');
    head->next->next->next->next = new Node('R');

    cout << boolalpha;
    cout << isPalindrome(head) << endl; // theta(n) and theta(1)
    return 0;
}
