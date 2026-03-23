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

int maxWidth(Node* root) {
    if (root == NULL) {
        return 0;
    }
    queue<Node*> q;
    q.push(root);
    int res = 0;
    while (!q.empty()) {
        int count = q.size();
        res = max(res,count);
        for (int i = 0; i < count; i++) {
            Node* cur = q.front();
            q.pop();
            if (cur->left != NULL) {
                q.push(cur->left);
            }
            if (cur->right != NULL) {
                q.push(cur->right);
            }
        }
    }
    return res;
}

int main() {
    Node* root = NULL;
    root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    cout << maxWidth(root) << endl; // theta(n) and O(width)
    return 0;

}