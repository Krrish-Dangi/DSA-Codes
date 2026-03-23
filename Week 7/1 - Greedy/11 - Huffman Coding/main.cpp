#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(char ch, int freq, Node* left, Node* right) {
        this->ch = ch;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }
};

struct compare {
    bool operator() (Node* l, Node* r) {
        return l->freq < r->freq;
    }
};

void printCodes(Node* root, string str) {
    if (root->ch != '$') {
        cout << root->ch << " " << str << endl;
        return;
    }

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

Node* buildTree(char chars[], int freq[], int n) {
    priority_queue<Node*, vector<Node*>, compare> pq;
    for (int i = 0; i < n; i++) {
        pq.push(new Node(chars[i], freq[i], NULL, NULL));
    }

    while (pq.size() > 1) {
        Node* l = pq.top(); pq.pop();
        Node* r = pq.top(); pq.pop();

        Node* newNode = new Node('$', l->freq + r->freq, l, r);
        pq.push(newNode);
    }

    printCodes(pq.top(), "");
}