#include <iostream>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

struct Node {
    float data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, float value) {
    if (root == nullptr) {
        root = (Node*)malloc(sizeof(Node));
        root->data = value;
        root->left = nullptr;
        root->right = nullptr;
    } else {
        if (root->left == nullptr)
            root->left = insert(root->left, value);
        else if (root->right == nullptr)
            root->right = insert(root->right, value);
        else
            insert(root->left, value);
    }
    return root;
}

void mirrorTree(Node* root) {
    if (root == nullptr)
        return;

    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorTree(root->left);
    mirrorTree(root->right);
}

void printPreorder(Node* root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    Node* root = NULL;
    root = insert(root, 2);
    root = insert(root, 11);
    root = insert(root,22);
    root = insert(root, 33);
    root = insert(root, 44);
    root = insert(root, 4);
    root = insert(root, 5);

    cout << "Original Tree Preorder: ";
    printPreorder(root);
    cout << endl;

    // Mirror the binary tree
    mirrorTree(root);

    cout << "Mirror Image Tree Preorder: ";
    printPreorder(root);
    cout << endl;

    return 0;
}
