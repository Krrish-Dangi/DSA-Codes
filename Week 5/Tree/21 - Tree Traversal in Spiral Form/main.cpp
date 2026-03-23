#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    Node(int k) {
        key = k;
        left = NULL;
        right = NULL;
    }
};

void Method1(Node* root) {
    if (root == NULL) {
        return;
    }
    queue<Node*> q;
    stack<int> s;
    bool flag = false;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* temp = q.front();
            q.pop();
            if (flag) {
                s.push(temp->key);
            }else {
                cout << temp->key << " ";
            }
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
        if (flag) {
            while (!s.empty()) {
                cout << s.top() << " ";
                s.pop();
            }
        }
        flag = !flag;
        cout << endl;
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->right->left->left = new Node(10);
    Method1(root); // O(n) and O(width)
}