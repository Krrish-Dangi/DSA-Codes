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


// Method 1 - with the help of preorder traversal
int maxLevel = 0;
void printLeft(Node* root, int level) {
    if (root == NULL) {
        return;
    }
    if (maxLevel < level) {
        cout << root->key << " ";
        maxLevel = level;
    }
    printLeft(root->left, level + 1);
    printLeft(root->right, level + 1);
}

void LeftView(Node* root) {
    printLeft(root, 1);
}

// Method 2 - with the help of level order traversal
void best(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);
    while (q.empty() == false) {
        int count = q.size();
        for (int i = 0; i < count; i++) {
            Node* curr = q.front();
            q.pop();
            if (i == 0) {
                cout << curr->key << " ";
            }
            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }
    }
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(60);
    LeftView(root); // O(1) and O(height)
    cout << endl;
    best(root); // O(n) and O(width)
    return 0;
}