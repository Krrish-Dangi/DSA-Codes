#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int x) {
        key = x;
        left = NULL;
        right = NULL;
    }
};

// // RECURSIVE // O(height) and O(height)
// Node* insert(Node* root, int x) {
//     if (root == NULL) {
//         root = new Node(x);
//         return root;
//     }
//
//     if (root->key > x) {
//         root->left = insert(root->left, x);
//     }else {
//         root->right = insert(root->right, x);
//     }
//     return root;
// }

// ITERATIVE // O(height)
Node* insert(Node* root, int x) {
    Node* temp = new Node(x);
    Node* parent = NULL;
    Node* curr = root;
    while (curr != NULL) {
        parent = curr;
        if (curr->key > x) {
            curr = curr->left;
        }else if (curr->key < x) {
            curr = curr->right;
        }else {
            return temp;
        }
    }
    if (parent == NULL) {
        return temp;
    }
    if (parent->key > x) {
        parent->left = temp;
    }else {
        parent->right = temp;
    }
    return root;
}

int main() {
    Node* root = new Node(NULL);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);

    return 0;
}