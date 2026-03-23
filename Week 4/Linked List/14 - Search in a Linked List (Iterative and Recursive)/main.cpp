// No Binary Search of (logn) because Linked list is not contiguous and hence do not allow to find mid elem in theta(1) time

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node (int x) {
        data = x;
        next = NULL;
    }
};

int Search (Node* head, int key) {
    int pos = 1;
    while (head != NULL) {
        if (head->data == key) {
            return pos;
        }
        pos++;
        head = head->next;
    }
    return -1;
}

void printList (Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int SearchRecursive(Node* head, int key) {
    if (head == NULL) {
        return -1;
    }
    if (head->data == key) return 1;
    else {
        int res = SearchRecursive(head->next, key);
        if (res == -1) return -1;
        else return res+1;
    }
}

int main() {
    Node* head = NULL;
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    int key = 2;
    cout << Search(head, key) << endl; // O(n)
    cout << SearchRecursive(head, key) << endl; // O(n) and O(n)
    // printList(head);
    return 0;
}