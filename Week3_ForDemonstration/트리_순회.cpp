#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

Node* createNode(char data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* searchNode(Node* root, char data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    
    Node* leftResult = searchNode(root->left, data);
    if (leftResult != NULL) {
        return leftResult;
    }
    
    return searchNode(root->right, data);
}

Node* buildTree(int N) {
    Node* root = NULL;
    char data, leftData, rightData;
    
    for (int i = 0; i < N; i++) {
        cin >> data >> leftData >> rightData;
        if (root == NULL) {
            root = createNode(data);
        }
        
        Node* node = NULL;
        for (int j = 0; j < i + 1; j++) {
            node = searchNode(root, data);
            if (node != NULL) {
                break;
            }
        }
        
        if (leftData != '.') {
            node->left = createNode(leftData);
        }
        if (rightData != '.') {
            node->right = createNode(rightData);
        }
    }
    
    return root;
}

void preorder(Node* node) {
    if (node == NULL) {
        return;
    }
    
    cout << node->data;
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node* node) {
    if (node == NULL) {
        return;
    }
    
    inorder(node->left);
    cout << node->data;
    inorder(node->right);
}

void postorder(Node* node) {
    if (node == NULL) {
        return;
    }
    
    postorder(node->left);
    postorder(node->right);
    cout << node->data;
}

int main() {
    int N;
    cin >> N;
    
    Node* root = buildTree(N);
    
    preorder(root);
    cout << "\n";
    
    inorder(root);
    cout << "\n";
    
    postorder(root);
    cout << "\n";
    
    return 0;
}
