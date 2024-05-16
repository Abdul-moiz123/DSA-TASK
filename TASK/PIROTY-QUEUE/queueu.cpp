#include <iostream>

using namespace std;

struct Record {
    string data;
    int priority;
    Record* next;
};

Record* front_end = NULL; // Change nullptr to NULL
Record* rear_end = NULL; // Change nullptr to NULL

// INSERT FUNCTION
void insert(string data, int priority) {
    Record* ptr = new Record(); // Using new instead of malloc
    ptr->data = data;
    ptr->priority = priority;
    ptr->next = NULL; // Change nullptr to NULL

    if (front_end == NULL && rear_end == NULL) { // Change nullptr to NULL
        front_end = ptr;
        rear_end = ptr;
        cout << "The Record has been inserted" << endl;
        return;
    }

    if (priority > front_end->priority) {
        ptr->next = front_end;
        front_end = ptr;
        cout << "The Record has been inserted" << endl;
        return;
    }

    Record* curr = front_end;
    while (curr->next != NULL && curr->next->priority >= priority) { // Change nullptr to NULL
        curr = curr->next;
    }
    ptr->next = curr->next;
    curr->next = ptr;

    cout << "The Record has been inserted" << endl;
}

// DELETE VALUE FUNCTION
void delete_value() {
    if (front_end == NULL && rear_end == NULL) { // Change nullptr to NULL
        cout << "The list is empty" << endl;
        return;   
    }
    
    Record* curr = front_end;
    if (front_end == rear_end) {
        front_end = NULL; // Change nullptr to NULL
        rear_end = NULL; // Change nullptr to NULL
    } else {
        front_end = front_end->next;
    }
    delete curr; // Using delete instead of free
    cout << "The data has been deleted" << endl;
}

// PRINT FUNCTION
void print_queue() {
    Record* curr = front_end;
    if (curr == NULL) { // Change nullptr to NULL
        cout << "The queue is empty" << endl;
        return;
    }
    cout << "Tasks in priority order:" << endl;
    while (curr != NULL) { // Change nullptr to NULL
        cout << "Task: " << curr->data << " Priority: " << curr->priority << endl;
        curr = curr->next;
    }
}

int main() {
    int choice;
    string data;
    int priority;

    while (true) {
        cout << "1. Insert Record\n";
        cout << "2. Delete Record\n";
        cout << "3. Print Records\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the task name: ";
                cin >> data;
                cout << "Enter the priority for the task: ";
                cin >> priority;
                insert(data, priority);
                break;
            case 2:
                delete_value();
                break;
            case 3:
                print_queue();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}
