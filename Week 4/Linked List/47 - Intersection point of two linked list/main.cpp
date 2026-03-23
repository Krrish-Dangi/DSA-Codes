#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

int findIntersectionPoint(Node *head1, Node *head2) {
    // Count length of first list
    Node *temp1 = head1;
    int c1 = 0;
    while (temp1 != NULL) {
        c1++;
        temp1 = temp1->next;
    }

    // Count length of second list
    Node *temp2 = head2;
    int c2 = 0;
    while (temp2 != NULL) {
        c2++;
        temp2 = temp2->next;
    }

    int d = abs(c1 - c2);

    // Reset pointers
    temp1 = head1;
    temp2 = head2;

    // Advance longer list by d nodes
    if (c1 > c2) {
        for (int i = 0; i < d; i++) {
            temp1 = temp1->next;
        }
    } else {
        for (int i = 0; i < d; i++) {
            temp2 = temp2->next;
        }
    }

    // Move both pointers together until intersection is found
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1 == temp2) {
            return temp1->data;  // Intersection point data
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return -1; // No intersection
}

int main() {
    Node *h1 = NULL;
    h1 = new Node(1);
    h1->next = new Node(2);
    h1->next->next = new Node(3);
    h1->next->next->next = new Node(4);
    h1->next->next->next->next = new Node(5);

    Node* h2 = NULL;
    h2 = new Node(-2);
    h2->next = new Node(-1);
    h2->next->next = new Node(0);

    // Linking intersection
    h2->next->next->next = h1->next->next; // h2 intersects at node with value 3

    cout << "Intersection Point: " << findIntersectionPoint(h1,h2) << endl;

    return 0;
}
