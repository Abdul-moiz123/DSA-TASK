#include <iostream>
#include <cstdlib>
#include <stack>

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to insert a node into the binary search tree
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        Node* ptr = (Node*)malloc(sizeof(Node));
        ptr->data=value;
        ptr->left=NULL;
        ptr->right=NULL;    
        return ptr;
    }
    else{
        if (value < root->data) {
            root->left = insert(root->left, value);
        } else if (value > root->data) {
            root->right = insert(root->right, value);
        }
    }
    return root;
}


// Function to check if two binary search trees are equal
bool isEqual(Node* root1, Node* root2) {
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 == nullptr || root2 == nullptr)
        return false;
    return (root1->data == root2->data) && isEqual(root1->left, root2->left) && isEqual(root1->right, root2->right);
}


// Function to check if two binary search trees have the same structure
bool hasSameStructure(Node* root1, Node* root2) {
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 == nullptr || root2 == nullptr)
        return false;
    return hasSameStructure(root1->left, root2->left) && hasSameStructure(root1->right, root2->right);
}

void sortDescending(Node* root) {
    if (root == nullptr)
        return;
    sortDescending(root->right);
    std::cout << root->data << " ";
    sortDescending(root->left);
}


int main() {
    // Construct the first binary search tree
    Node* root1 = nullptr;
    root1 = insert(root1, 50);
    insert(root1, 30);
    insert(root1, 70);
    insert(root1, 20);
    insert(root1, 40);

    // Construct the second binary search tree
    Node* root2 = nullptr;
    root2 = insert(root2, 50);
    insert(root2, 30);
    insert(root2, 70);
    insert(root2, 20);
    insert(root2, 40);

    // Check if the trees are equal
    std::cout << "Are the trees equal? " << (isEqual(root1, root2) ? "Yes" : "No") << std::endl;

    // Check if the trees have the same structure
    std::cout << "Do the trees have the same structure? " << (hasSameStructure(root1, root2) ? "Yes" : "No") << std::endl;

    // Sort the nodes in descending order
    std::cout << "Nodes in descending order: ";
    sortDescending(root1);
    std::cout << std::endl;

    return 0;
}