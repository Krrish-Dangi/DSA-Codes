#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printNodes(Node* root, int k) {
    if (root == NULL) {
        return;
    }

    if (k == 0) cout << root->data << " ";
    else {
        printNodes(root->left, k - 1);
        printNodes(root->right, k - 1);
    }


}

int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->right = new Node(70);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    int k = 2;
    printNodes(root, k); // O(n) and O(hegiht)

    return 0;
}