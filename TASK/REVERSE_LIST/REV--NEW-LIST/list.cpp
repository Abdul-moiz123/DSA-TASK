#include <iostream>
#include <stdlib.h>
using namespace std;

struct Record {
    int data;
    Record* next;
    Record* prev;
};

Record* head = NULL;
Record* tail = NULL;

// SORTED INSERT FUNCTION
void insert(int data) {
    Record* ptr = (Record*)malloc(sizeof(Record));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    if (head == NULL) {
        head = ptr;
        tail = ptr;
    } else if (ptr->data < head->data) {
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    } else {
        Record* curr = head;
        while (curr->next != NULL && ptr->data > curr->next->data) {
            curr = curr->next;
        }
        ptr->next = curr->next;
        if (curr->next != NULL) {
            curr->next->prev = ptr;
        } else {
            tail = ptr;
        }
        ptr->prev = curr;
        curr->next = ptr;
    }
}

void print() {
    cout << "List: ";
    Record* curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void reverse_list_into_new_list() {
    Record* curr = tail;
    Record* new_head = NULL;
    Record* new_tail = NULL;

    while (curr != NULL) {
        Record* ptr = (Record*)malloc(sizeof(Record));
        ptr->data = curr->data;
        ptr->next = NULL;
        ptr->prev = new_tail;
        if (new_tail != NULL) {
            new_tail->next = ptr;
        } else {
            new_head = ptr;
        }
        new_tail = ptr;
        curr = curr->prev;
    }
    head = new_head;
    tail = new_tail;
}

int main() {
    insert(23);
    insert(213);
    insert(223);
    insert(233);
    insert(243);
    insert(523);
    insert(263);

    cout << "Original List:" << endl;
    print();

    cout << endl;

    cout << "Reversed List:" << endl;
    reverse_list_into_new_list();
    print();

    return 0;
}
