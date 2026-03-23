#include <iostream>
using namespace std;

struct TNode {
    int key;
    TNode *left;
    TNode *right;
    TNode(int x) {
        key = x;
        left = NULL;
        right = NULL;
    }
};

struct LNode {
    int data;
    LNode *next;
    LNode *prev;
    LNode(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

void convertTree(TNode* root, LNode*& head, LNode*& prev) {
    if (root == NULL) return;

    convertTree(root->left, head, prev);

    LNode* node = new LNode(root->key);
    if (prev == NULL) {
        head = node; // first node becomes head
    } else {
        prev->next = node;
        node->prev = prev;
    }
    prev = node;

    convertTree(root->right, head, prev);
}

void printList(LNode* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    TNode* root = new TNode(10);
    root->left = new TNode(5);
    root->right = new TNode(20);
    root->right->left = new TNode(30);
    root->right->right = new TNode(35);

    LNode* head = NULL;
    LNode* prev = NULL;

    convertTree(root, head, prev); // O(n) and O(height)
    printList(head);

    return 0;
}
