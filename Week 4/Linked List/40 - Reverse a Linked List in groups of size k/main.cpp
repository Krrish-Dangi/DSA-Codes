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

Node* RecursiveReverse(Node* head, int k) {
    Node* curr = head, *next = NULL, *prev = NULL;
    int count = 0;
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != NULL) {
        Node* restHead = RecursiveReverse(next, k);
        head->next = restHead;
    }
    return prev;
}

Node* IterativeReverse(Node* head, int k) {
    Node* curr = head, *prevFirst = NULL;
    bool isFirstPass = true;
    while (curr != NULL) {
        Node* first = curr, *prev = NULL;
        int count = 0;
        while (curr != NULL && count < k) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (isFirstPass) {
            head = prev;
            isFirstPass = false;
        }else {
            prevFirst->next = prev;
        }
            prevFirst = first;
    }
    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    // head = RecursiveReverse(head, 3); // theta(n) and theta(n/k)
    head = IterativeReverse(head,3); // theta(n**2)
    printList(head);
}