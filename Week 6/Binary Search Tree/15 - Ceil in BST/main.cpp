#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int x) {
        key = x;
        left = right = NULL;
    }
};

Node* Ceil(Node* root, int x) { // O(height)
    Node* res = NULL;
    while (root != NULL) {
        if (root->key == x) {
            return root;
        }else if (root->key > x) {
            res = root;
            root = root->left;
        }else {
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
    Node* temp = Ceil(root, 14);
    cout << temp->key << endl;
    Node* temp1 = Ceil(root, 3);
    cout << temp1->key << endl;
    Node* temp2 = Ceil(root, 40);
    if (temp2 == NULL) {
        cout << INT_MIN << endl;
    }else {
        cout << temp->key << endl;
    }

}