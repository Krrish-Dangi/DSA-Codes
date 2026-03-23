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

Node* Segregate(Node* head) {
    Node* es = NULL, *ee = NULL, *os = NULL, *oe = NULL;
    for (Node* curr = head; curr != NULL; curr = curr->next) {
        int x = curr->data;
        if (x%2 == 0) {
            if (es == NULL) {
                es = curr;
                ee = curr;
            }else {
                ee->next = curr;
                ee = ee->next;
            }
        }else {
            if (os == NULL) {
                os = curr;
                oe = curr;
            }else {
                oe->next = curr;
                oe = oe->next;
            }
        }
    }
    if (os == NULL || es == NULL) {
        return head;
    }
    ee->next = os;
    oe->next = NULL;
    return es;
}

void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    head = new Node(17);
    head->next = new Node(15);
    head->next->next = new Node(8);
    head->next->next->next = new Node(12);
    head->next->next->next->next = new Node(5);

    head = Segregate(head); // theta(n)
    print(head);


    return 0;
}