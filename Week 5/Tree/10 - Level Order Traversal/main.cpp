// Level order traversal - print nodes level by level (from left to right)
#include <iostream>
#include <queue>

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

void LevelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->key << " ";
        if (curr->left != NULL) {
            q.push(curr->left);
        }
        if (curr->right != NULL) {
            q.push(curr->right);
        }
    }
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(8);
    root->left->right = new Node(7);
    root->left->right->left = new Node(9);
    root->left->right->right = new Node(15);
    root->right->right = new Node(6);
    // Inefficient way -> height nikalo -> levels print kro (O(n*k))
    LevelOrderTraversal(root); // theta(1) and O(n) or theta(width)
}