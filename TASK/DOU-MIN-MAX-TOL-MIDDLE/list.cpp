#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

struct Record {
    int data;
    Record* next;
    Record* prev;
};

Record* head = NULL;
Record* tail = NULL;

// INSERT FUNCTION
void insert(int data) {
    Record* ptr = (Record*)malloc(sizeof(Record));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;

    if (head == NULL) {
        head = ptr;
        tail = ptr;
    }
    
    else {
        tail->next = ptr;
        ptr->prev = tail;
        tail = ptr;
    }
}


// PRINT FUNCTION
void print() {
    if (head == NULL) {
        cout << "The list is empty" << endl;
        return;
    }
    Record* curr = head;
    while (curr != NULL) {
        cout << "Data: " << curr->data << endl;
        curr = curr->next;
    }
}


// DELETE VALUE FUNCTION
void delete_value(int data) {
    if (head == NULL) {
        cout << "The list is empty" << endl;
        return;
    }

    Record* curr = head;
    while (curr != NULL && curr->data != data) {
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "Value not found" << endl;
        return;
    }

    if (curr == head && curr == tail) {
        head = tail = NULL;
    }
    
    else if (curr == head) {
        head = head->next;
        head->prev = NULL;
    }
    
    else if (curr == tail) {
        tail = tail->prev;
        tail->next = NULL;
    }
    
    else {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }
    free(curr);
}



// MOVE MINIMUM NODE TO START
void move_min_to_start() {
    if (head == NULL) {
        cout << "Empty list" << endl;
        return;
    }

    Record* min_node = head;
    Record* curr = head->next;

    while (curr != NULL) {
        if (curr->data < min_node->data) {
            min_node = curr;
        }
        curr = curr->next;
    }

    if (min_node == head) {
        cout << "Min node is already at the start" << endl;
        return;
    }

    if (min_node != head) {
        min_node->prev->next = min_node->next;
        if (min_node != tail) {
            min_node->next->prev = min_node->prev;
        } else {
            tail = min_node->prev;
        }

        min_node->next = head;
        head->prev = min_node;
        head = min_node;
        head->prev = NULL;
    }
}

// MOVE MAXIMUM NODE TO END
void move_max_to_end() {
    if (head == NULL) {
        cout << "Empty list" << endl;
        return;
    }

    Record* max_node = head;
    Record* curr = head->next;

    while (curr != NULL) {
        if (curr->data > max_node->data) {
            max_node = curr;
        }
        curr = curr->next;
    }

    if (max_node == tail) {
        cout << "Maximum node is already at the end" << endl;
        return;
    }

    if(max_node!=tail){
        max_node->prev->next = max_node->next;
        if (max_node !=head) {
            max_node->next->prev=max_node->prev;
        } else {
            head= max_node->next;
        }

        tail->next = max_node;
        max_node->prev = tail;
        max_node->next = NULL;
        tail = max_node;
    }
}

// FIND MIDDLE NODE
int middle_node() {
    if (head == NULL) {
        cout << "Empty list" << endl;
        return -1;
    }

    Record* slow = head;
    Record* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

// COUNT NODE FUNCTION
int count_node() {
    int count = 0;
    Record* curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

// MAIN FUNCTION
int main() {
    insert(34);
    insert(134);
    insert(24);
    insert(124);
    insert(3444);
    insert(14);
    insert(4);

    cout << "Original List:" << endl;
    print();
    cout << endl;

    delete_value(24);

    cout << "After deleting 24:" << endl;
    print();
    cout << endl;

    move_min_to_start();

    cout << "After moving minimum node to start:" << endl;
    print();
    cout << endl;

    move_max_to_end();

    cout << "After moving maximum node to start:" << endl;
    print();
    cout << endl;

    cout << "Total nodes: " << count_node() << endl;

    cout << "Middle node: " << middle_node() << endl;

    return 0;
}
