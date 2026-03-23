#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* random;
    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

Node* createClone(Node* head) {
    if (!head) return NULL;

    unordered_map<Node*, Node*> m;
    Node* curr = head;

    // Step 1: Create clone nodes for each original node
    while (curr != NULL) {
        m[curr] = new Node(curr->data);
        curr = curr->next;
    }

    // Step 2: Assign next and random pointers
    curr = head;
    while (curr != NULL) {
        m[curr]->next = m[curr->next];       // next pointer
        m[curr]->random = m[curr->random];   // random pointer
        curr = curr->next;
    }

    // Return cloned head
    return m[head];
}

Node* best(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        Node* next = curr->next;
        curr->next = new Node(curr->data);
        curr->next->next = next;
        curr = next;
    }

    for (Node* curr = head; curr != NULL; curr = curr->next->next) {
        curr->next->random = (curr->random == NULL) ? NULL: curr->random->next;
    }
    Node* h2 = head->next;
    Node* clone = h2;
    for (Node* curr = head; curr != NULL; curr = curr->next) {
        curr->next = curr->next->next;
        clone->next = curr->next ? clone ->next->next : NULL;
        clone = clone->next;
    }
    return h2;
}

// Utility function to print list with random pointers
void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        cout << "Data: " << curr->data;
        if (curr->random)
            cout << " | Random: " << curr->random->data;
        else
            cout << " | Random: NULL";
        cout << endl;
        curr = curr->next;
    }
    cout << "--------------------------" << endl;
}

int main() {
    Node* head = new Node(1);
    Node* elem1 = new Node(5);
    Node* elem2 = new Node(20);
    Node* elem3 = new Node(15);
    Node* elem4 = new Node(20);

    head->next = elem1;
    elem1->next = elem2;
    elem2->next = elem3;
    elem3->next = elem4;

    // Assign random pointers
    head->random = elem2;
    elem1->random = elem3;
    elem2->random = head;
    elem3->random = elem2;
    elem4->random = elem3;

    cout << "Original List:\n";
    printList(head);

    // Node* clonedHead = createClone(head); // theta(n) and theta(n)
    Node* clonedHead = best(head); // theta(n) and theta(1)
    cout << "Cloned List:\n";
    printList(clonedHead);

    return 0;
}
