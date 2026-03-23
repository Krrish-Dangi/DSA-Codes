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

int findMax(Node* root) {
    if (root == NULL) {
        return INT_MIN;
    }
    return max(root->key,max(findMax(root->left), findMax(root->right)));
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(30);
    root->right = new Node(40);
    root->left->left = new Node(80);
    root->left->left->right = new Node(70);
    root->right->left = new Node(60);
    root->right->right = new Node(20);
    cout << findMax(root) << endl; // O(1) and O(height)

    return 0;
}