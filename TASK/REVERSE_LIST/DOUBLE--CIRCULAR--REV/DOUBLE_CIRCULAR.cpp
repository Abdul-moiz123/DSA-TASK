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

void insert(int data) {
    Record* ptr = (Record*)malloc(sizeof(Record));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;

    if (head == NULL) {
        head = ptr;
        tail = ptr;
    } else {
        tail->next = ptr;
        ptr->prev = tail;
        tail = ptr;
    }
}

void print() {
    Record* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    }while (curr != head);
    cout << endl;
}

// REVERSE THE LIST
void reverse_list() {
    Record* curr = head;
    Record* momo = NULL;

    do{
        momo = curr->prev;
        curr->prev = curr->next;
        curr->next = momo;
        curr = curr->prev;
    }while (curr != head);
    if (momo != head) {
        head = momo->prev;
    }
}

// min value in list
int find_min() {
    if (head == NULL) {
        return -1;
    }
    Record* curr = head;
    int min = head->data;
    do {
        if (curr->data < min) {
            min = curr->data;
        }
        curr = curr->next;
    }while (curr != head);
    return min;
}

// max value in list
int find_max() {
    if (head == NULL) {
        return -1;
    }
    Record* curr = head;
    int max = head->data;
    do{
        if (curr->data > max) {
            max = curr->data;
        }
        curr = curr->next;
    }while (curr != head) ;
    return max;
}

int main() {
    insert(100);
    insert(211);
    insert(321);
    insert(413);
    insert(541);
    insert(165);
    
    // Convert doubly linked list to circular linked list
    tail->next = head;
    head->prev = tail;

    cout << endl;
    print();
    cout << endl;
    reverse_list();
    cout << endl;
    print();
    cout << endl;
    cout << "Max value: " << find_max() << endl;
    cout << "Min value: " << find_min() << endl;

    return 0;
}
