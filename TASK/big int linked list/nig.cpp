#include <iostream>
using namespace std;

struct Node {
    int digit;
    Node* next;
};

// Function to create a new node with given digit
Node* createNode(int digit) {
    Node* newNode = new Node;
    newNode->digit = digit;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a digit at the end of a linked list
void insertNode(Node*& head, int digit) {
    Node* newNode = createNode(digit);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display a big integer represented by a linked list
void displayBigNumber(Node* head) {
    if (head == nullptr) {
        cout << "0";
        return;
    }
    Node* curr = head;
    while (head != nullptr) {
        cout << head->digit;
        head = head->next;
    }
}

// Function to add two big integers represented by linked lists
Node* addBigIntegers(Node* num1, Node* num2) {
    Node* result = nullptr;
    Node* tail = nullptr; // Pointer to the tail of the result linked list
    int carry = 0;

    // Traverse both linked lists until both are empty
    while (num1 != nullptr || num2 != nullptr || carry) {
        int sum = carry;
        if (num1 != nullptr) {
            sum += num1->digit;
            num1 = num1->next;
        }
        if (num2 != nullptr) {
            sum += num2->digit;
            num2 = num2->next;
        }
        carry = sum / 10; // Update carry
        sum %= 10; // Update sum to single digit

        // Insert the sum digit at the beginning of the result linked list
        Node* newNode = createNode(sum);
        newNode->next = result;
        result = newNode;
    }
    return result;
}

// Function to subtract two big integers represented by linked lists
Node* subtractBigIntegers(Node* num1, Node* num2) {
    // Implementation of subtraction not included for brevity
    // You can implement subtraction similarly to addition, considering borrow
    return nullptr;
}

// Function to multiply two big integers represented by linked lists
Node* multiplyBigIntegers(Node* num1, Node* num2) {
    // Implementation of multiplication not included for brevity
    return nullptr;
}

int main() {
    // Example usage:
    Node* num1 = nullptr;
    Node* num2 = nullptr;

    insertNode(num1, 3);
    insertNode(num1, 2);
    insertNode(num1, 1);

    insertNode(num2, 9);
    insertNode(num2, 8);
    insertNode(num2, 7);

    cout << "Number 1: ";
    displayBigNumber(num1);
    cout << endl;

    cout << "Number 2: ";
    displayBigNumber(num2);
    cout << endl;

    Node* sum = addBigIntegers(num1, num2);
    cout << "Sum: ";
    displayBigNumber(sum);
    cout << endl;

    return 0;
}
