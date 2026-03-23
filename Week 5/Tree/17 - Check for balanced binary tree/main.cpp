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

int height(Node* root) {
    if (root == NULL) {
        return 0;
    }else {
        return 1 + max(height(root->left), height(root->right));
    }
}

bool naive(Node* root) {
    if (root == NULL) {
        return true;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return abs(lh-rh) <= 1 && naive(root->left) && naive(root->right);
}

int best(Node* root) {
   if (root == NULL) {
       return 0;
   }
    int lh = best(root->left);
    if (lh == -1) return -1;
    int rh = best(root->right);
    if (rh == -1) return -1;
    if (abs(lh-rh) > 1) return -1;
    else return max(lh,rh)+1;
}

int main() {
    Node* root = new Node(18);
    root->left = new Node(4);
    root->right = new Node(20);
    root->right->left = new Node(13);
    root->right->right = new Node(70);
    cout << boolalpha << naive(root); // O(n**2)
    cout << endl;
    bool ans = best(root) > 0 ? true : false; // O(n)
    cout << ans;

}