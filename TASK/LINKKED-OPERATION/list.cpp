#include <iostream>
using namespace std;

// Define the structure for the linked list node
struct Node {
    int data;
    Node* next;
};

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to perform union operation on two linked lists representing sets
Node* unionOperation(Node* list1, Node* list2) {
    Node* result = nullptr;
    Node* tail = nullptr;

    while (list1 != nullptr || list2 != nullptr) {
        int val;
        if (list1 == nullptr) {
            val = list2->data;
            list2 = list2->next;
        } else if (list2 == nullptr) {
            val = list1->data;
            list1 = list1->next;
        } else if (list1->data < list2->data) {
            val = list1->data;
            list1 = list1->next;
        } else if (list1->data > list2->data) {
            val = list2->data;
            list2 = list2->next;
        } else {
            val = list1->data; // If data is same in both lists, include only once
            list1 = list1->next;
            list2 = list2->next;
        }

        Node* newNode = createNode(val);
        if (result == nullptr) {
            result = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return result;
}

// Function to perform intersection operation on two linked lists representing sets
Node* intersectionOperation(Node* list1, Node* list2) {
    Node* result = nullptr;
    Node* tail = nullptr;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data < list2->data) {
            list1 = list1->next;
        } else if (list1->data > list2->data) {
            list2 = list2->next;
        } else {
            Node* newNode = createNode(list1->data);
            if (result == nullptr) {
                result = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            list1 = list1->next;
            list2 = list2->next;
        }
    }

    return result;
}

// Function to perform difference operation on two linked lists representing sets
Node* differenceOperation(Node* list1, Node* list2) {
    Node* result = nullptr;
    Node* tail = nullptr;

    while (list1 != nullptr) {
        if (list2 == nullptr || list1->data < list2->data) {
            Node* newNode = createNode(list1->data);
            if (result == nullptr) {
                result = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            list1 = list1->next;
        } else if (list1->data > list2->data) {
            list2 = list2->next;
        } else {
            list1 = list1->next;
            list2 = list2->next;
        }
    }

    return result;
}

// Function to insert a node with given data after every occurrence of target data in the linked list
void insertAfter(Node* head, int target, int newData) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == target) {
            Node* newNode = createNode(newData);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next; // Skip the newly inserted node
        } else {
            current = current->next;
        }
    }
}

// Function to merge two linked lists of numbers in ascending numerical order
Node* mergeOperation(Node* list1, Node* list2) {
    Node* dummy = createNode(0);
    Node* tail = dummy;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data < list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1 != nullptr) {
        tail->next = list1;
    }
    if (list2 != nullptr) {
        tail->next = list2;
    }

    Node* mergedList = dummy->next;
    delete dummy;
    return mergedList;
}

// Function to print the elements of a linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Example usage of the functions
    Node* list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(4);
    list1->next->next->next = createNode(7);
    list1->next->next->next->next = createNode(12);

    Node* list2 = createNode(1);
    list2->next = createNode(5);
    list2->next->next = createNode(7);
    list2->next->next->next = createNode(9);

    // UNION OPERATION
    Node* unionList = unionOperation(list1, list2);
    cout << "Union: ";
    printList(unionList);

    // INTERSECTION OPERATION
    Node* intersectionList = intersectionOperation(list1, list2);
    cout << "Intersection: ";
    printList(intersectionList);

    // DIFFERENCE OPERATION
    Node* diffList = differenceOperation(list1, list2);
    cout << "Difference: ";
    printList(diffList);

    // CUSTOMIZED INSERT
    insertAfter(list1, 2, 10);
    cout << "Customized Insert: ";
    printList(list1);

    // MERGE OPERATION
    Node* list3 = createNode(2);
    list3->next = createNode(3);
    list3->next->next = createNode(4);
    list3->next->next->next = createNode(8);
    list3->next->next->next->next = createNode(12);

    Node* list4 = createNode(1);
    list4->next = createNode(4);
    list4->next->next = createNode(5);
    list4->next->next->next = createNode(7);
    list4->next->next->next->next = createNode(9);

    Node* mergeResult = mergeOperation(list3, list4);
    cout << "Merge: ";
    printList(mergeResult);

    // Free memory
    Node* temp;
    while (list1 != nullptr) {
        temp = list1->next;
        delete list1;
        list1 = temp;
    }
    while (list2 != nullptr) {
        temp = list2->next;
        delete list2;
        list2 = temp;
    }
    while (unionList != nullptr) {
        temp = unionList->next;
        delete unionList;
        unionList = temp;
    }
    while (intersectionList != nullptr) {
        temp = intersectionList->next;
        delete intersectionList;
        intersectionList = temp;
    }
    while (diffList != nullptr) {
        temp = diffList->next;
        delete diffList;
        diffList = temp;
    }
    while (mergeResult != nullptr) {
        temp = mergeResult->next;
        delete mergeResult;
        mergeResult = temp;
    }

    return 0;
}
