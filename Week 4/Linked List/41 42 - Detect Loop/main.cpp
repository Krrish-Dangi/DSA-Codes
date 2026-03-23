#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

bool detectLoop(Node* head) {
    unordered_map<Node*, bool> m;
    Node* curr = head;
    while (curr != NULL) {
        if (m.find(curr) != m.end()) { // already visited
            return true;
        }
        m[curr] = true;
        curr = curr->next;
    }
    return false;
}

bool floydCycleDetection(Node* head) {
    Node* slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main() {
    Node* head = NULL;
    head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(12);
    head -> next -> next -> next = new Node(20);
    head -> next -> next -> next -> next = head->next;
    cout << boolalpha;
    cout << detectLoop(head) << endl; // theta(n) and theta(n)
    cout << floydCycleDetection(head) << endl; // theta(length of loop + position of start of loop)

    return 0;
}
