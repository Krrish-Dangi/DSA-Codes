/*
Leaf Node? -> No issue delete normally
Node with 1 child -> delete the Node and connect previous with next
Node with 2 child -> delete and replace it with the closest lower or higher value

Closest higher value -> Inorder successor
*/


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

Node* getSuccessor(Node* curr) {
    while (curr != NULL && curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

Node* DELETE(Node* root, int x) {
    if (root == NULL) {
        return NULL;
    }

    if (root->key > x) {
        root->left = DELETE(root->left, x);
    }else if (root->key < x) {
        root->right = DELETE(root->right, x);
    }else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* succ = getSuccessor(root->right);
            root->key = succ->key;
            root->right = DELETE(root->right, succ->key);
        }
    }
    return root;
}

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    root = DELETE(root, 40); // O(height) and O(height)


    return 0;
}