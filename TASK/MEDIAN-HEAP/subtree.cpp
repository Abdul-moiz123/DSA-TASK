#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    int level;
    int height;
    Node* left;
    Node* right;
};

// Function to find the median of an array
int findMedian(int arr[], int n) {
    if (n % 2 == 0) {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2;
    } else {
        return arr[n / 2];
    }
}

// Function to insert a node into the tree
Node* insert(Node*& root, int data, int level) {
    if (root == NULL) {
        root = new Node;
        root->data = data;
        root->level = level;
        root->height = 0;
        root->left = NULL;
        root->right = NULL;
    } else if (data <= root->data) {
        if (root->left != NULL) {
            insert(root->left, data, level + 1);
        } else {
            root->left = insert(root->left, data , level+1);
        }
    } else {
        if (root->right != NULL) {
            insert(root->right, data, level + 1);
        } else {
           root->right = insert(root->right, data , level+1);
        }
    }

    // Update height of the current node
    // Calculate the height of the left subtree
    int leftHeight;
    if (root->left != NULL) {
        leftHeight = root->left->height;
    } else {
        leftHeight = -1; // There is no left child
    }

    // Calculate the height of the right subtree
    int rightHeight;
    if (root->right != NULL) {
        rightHeight = root->right->height;
    } else {
        rightHeight = -1; // There is no right child
    }

    // Update the height of the current node
    if (leftHeight > rightHeight) {
        root->height = leftHeight + 1;
    } else {
        root->height = rightHeight + 1;
    }
    
}

// Function to traverse the tree and print node levels and heights
void traverse(Node* root) {
    if (root == NULL)
        return;
    cout << "Node: " << root->data << ", Level: " << root->level << ", Height: " << root->height << endl;
    traverse(root->left);
    traverse(root->right);
}

// Function to divide the array and build the tree recursively
Node* buildTree(int arr[], int n, int level) {
    if (n <= 0)
        return NULL;

    int median = findMedian(arr, n);
    Node* root = new Node;
    root->data = median;
    root->level = level;
    root->height = 0;
    root->left = NULL;
    root->right = NULL;

    int left_size = 0, right_size = 0;
    int left[n], right[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] < median) {
            left[left_size++] = arr[i];
        } else if (arr[i] > median) {
            right[right_size++] = arr[i];
        }
    }

    root->left = buildTree(left, left_size, level + 1);
    root->right = buildTree(right, right_size, level + 1);


    // Update height of the current node
    // Calculate the height of the left subtree
    int leftHeight;
    if (root->left != NULL) {
        leftHeight = root->left->height;
    } else {
        leftHeight = -1; // There is no left child
    }

    // Calculate the height of the right subtree
    int rightHeight;
    if (root->right != NULL) {
        rightHeight = root->right->height;
    } else {
        rightHeight = -1; // There is no right child
    }

    // Update the height of the current node
    if (leftHeight > rightHeight) {
        root->height = leftHeight + 1;
    } else {
        root->height = rightHeight + 1;
    }


    return root;
}

int main() {
    int arr[] = {3, 6, 2, 8, 5, 7, 1, 9, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array to find the median correctly
    sort(arr, arr + n);

    Node* root = buildTree(arr, n, 0);
    traverse(root);

    return 0;
}
