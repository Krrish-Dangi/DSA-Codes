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

int preIndex = 0;
Node* constructTree(int* in ,int is, int* pre, int ie){
    if(is > ie) return NULL;
    Node* root = new Node(pre[preIndex++]);
    int inIndex;
    for(int i = is; i <= ie; i++){
        if(in[i] == root->key){
            inIndex = i;
            break;
        }
    }
    root->left = constructTree(in,is, pre, inIndex-1);
    root->right = constructTree(in,inIndex+1,pre, ie);
    return root;
}

int main() {
    int in[] = {20,10,30};
    int pre[] = {10,20,30};
    Node* root = constructTree(in,0 ,pre, 3); // O(n**2), can use hashing for O(n)

    return 0;
}