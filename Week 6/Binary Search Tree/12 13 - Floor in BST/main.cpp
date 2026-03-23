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

Node* Floor(Node* root, int x) {
    Node* res = NULL;
    while (root != NULL) {
        if (root->key == x) {
            res = root;
        }else if (root->key > x) {
            root = root->left;
        }else {
            res = root;
            root = root->right;
        }
    }
    return res;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(30);
    Node* res = Floor(root, 14);
    cout << res->key << endl;

    return 0;
}