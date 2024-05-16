#include <iostream>
#include <cstdlib>

struct Node {
    float data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, float value) {
    if (root == NULL) {
        root = (Node*)malloc(sizeof(Node));
        root->data = value;
        root->left = NULL;
        root->right = NULL;
    } else {
        if (root->left == NULL)
            root->left = insert(root->left, value);
        else if (root->right == NULL)
            root->right = insert(root->right, value);
        else
            insert(root->left, value);
    }
    return root;
}

bool search(Node* root, float value) {
    if (root == NULL)
        return false;
    if (root->data == value)
        return true;
    return search(root->left, value) || search(root->right, value);
}

void findPredecessorAndSuccessor(Node* root, float value, float& predecessor, float& successor) {
    if (root == NULL)
        return;
    
    if (root->data == value) {
        // Find predecessor
        Node* temp = root->left;
        while (temp && temp->right)
            temp = temp->right;
        if (temp)
            predecessor = temp->data;

        // Find successor
        temp = root->right;
        while (temp && temp->left)
            temp = temp->left;
        if (temp)
            successor = temp->data;

        return;
    }

    if (value < root->data) {
        successor = root->data;
        findPredecessorAndSuccessor(root->left, value, predecessor, successor);
    } else {
        predecessor = root->data;
        findPredecessorAndSuccessor(root->right, value, predecessor, successor);
    }
}

int countNodes(Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    // Create the binary tree
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);

    // Search for an element
    float x = 7;
    if (search(root, x)) {
        std::cout << x << " is present in the tree.\n";

        float predecessor = -1, successor = -1;
        findPredecessorAndSuccessor(root, x, predecessor, successor);
        std::cout << "Predecessor of " << x << " is: " << predecessor << std::endl;
        std::cout << "Successor of " << x << " is: " << successor << std::endl;
    } else {
        std::cout << x << " is not present in the tree.\n";
    }

    // Count total number of nodes in the tree
    int totalNodes = countNodes(root);
    std::cout << "Total number of nodes in the tree: " << totalNodes << std::endl;

    return 0;
}
