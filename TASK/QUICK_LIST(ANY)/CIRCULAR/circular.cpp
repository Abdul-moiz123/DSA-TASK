#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

struct Record {
    int roll_no;
    int index;
    Record* next;
};


// INSERT FUNCTION
void insert(Record** head_ref, int data) {
    Record* ptr = (Record*)malloc(sizeof(Record));
    ptr->roll_no = data;
    ptr->next = NULL;

    if (*head_ref == NULL) {
        ptr->index = 0;
        *head_ref = ptr;
        ptr->next = *head_ref;
    }
    
    else {
        Record* curr = *head_ref;
        while (curr->next != *head_ref) {
            curr = curr->next;
        }
        curr->next = ptr;
        ptr->index = curr->index + 1;
        ptr->next = *head_ref;
    }
}


// SEARCH FUNCTION
void search(Record** head_ref) {
    if (*head_ref == NULL) {
        cout << "The list is empty" << endl;
        return;
    }

    Record* curr = *head_ref;
    int tosearch;
    cout << "Enter the roll no that you want to search: ";
    cin >> tosearch;

    do {
        if (curr->roll_no == tosearch) {
            cout << "The roll no is found to be: " << curr->roll_no << endl;
            cout << "The index is: " << curr->index << endl;
            cout << endl;
            return;
        }
        curr = curr->next;
    } while (curr != *head_ref);
    cout << "The Record has not been found in the list" << endl;
}


// PRINT FUNCTION
void print(Record** head_ref) {
    if (*head_ref == NULL) {
        cout << "The list is empty" << endl;
        return;
    }

    Record* curr = *head_ref;

    do {
        cout << "The Index is: " << curr->index << endl;
        cout << "The roll no is found to be: " << curr->roll_no << endl;
        cout << endl;
        curr = curr->next;
    } while (curr != *head_ref);
}


// DELETE VALUE FUNCTION
void delete_value(Record** head_ref, int todel) {
    if (*head_ref == NULL) {
        cout << "The list is empty" << endl;
        return;
    }

    Record* curr = *head_ref;
    Record* prev = NULL;
    
    if (curr->next == *head_ref && curr->roll_no==todel){ 
        free(curr);
        *head_ref = NULL;
        cout << "The Record has been deleted" << endl;
        return;
    } 
    
    do
    {
        if (curr->roll_no == todel) {
            if(prev==NULL){
                Record* tail = *head_ref;
                while (tail->next != *head_ref) {
                    tail = tail->next;
                }
                tail->next = *head_ref;
                *head_ref = curr->next;
                free(curr);
                Record* ind = *head_ref;
                do {
                    ind->index--;
                    ind = ind->next;
                } while (ind != *head_ref);
                cout << "The Record has been deleted" << endl;
                return;
            }
            else{
                prev->next = curr->next;
                free(curr);
                Record* ind1 = prev->next;
                do {
                    ind1->index--;
                    ind1 = ind1->next;
                } while (ind1 != *head_ref);
                cout << "The Record has been deleted" << endl;
                return;
            }
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    } while (curr!=*head_ref);
}


// DELETE LIST FUNCTION
void delete_list(Record** head_ref) {
    if (*head_ref == NULL) {
        cout << "The list is already empty" << endl;
        return;
    }
    Record* curr = *head_ref;
    Record* next;
    do {
        next = curr->next;
        free(curr);
        curr = next;
    } while (curr != *head_ref);
    *head_ref = NULL;
    cout << "The list has been deleted" << endl;
}


// LENGTH OF LIST FUNCTION
int length_of_list(Record** head_ref) {
    if (*head_ref == NULL) return 0;
    Record* curr = *head_ref;
    int len = 0;
    do {
        len++;
        curr = curr->next;
    } while (curr != *head_ref);
    return len;
}


// CONVERT LIST TO ARRAY FUNCTION
void convert_list_to_array(Record** head_ref, int* arr) {
    if (*head_ref == NULL) return;
    Record* curr = *head_ref;
    int i = 0;
    do {
        arr[i] = curr->roll_no;
        curr = curr->next;
        i++;
    } while (curr != *head_ref);
}


// CONVERT ARRAY TO LIST FUNCTION
void convert_array_to_list(Record** head_ref, int* arr, int len) {
    delete_list(head_ref);
    for (int a = 0; a < len; a++) {
        insert(head_ref, arr[a]);
    }
}


// PARTITION FUNCTION
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

// QUICK SORT FUNCTION
void Quick_Sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        Quick_Sort(arr, low, pivot_index - 1);
        Quick_Sort(arr, pivot_index + 1, high);
    }
}


// SORTED LIST FUNCTION
void sorted_list(Record** head_ref) {
    int len = length_of_list(head_ref);
    int* arr = new int[len];
    convert_list_to_array(head_ref, arr);
    Quick_Sort(arr, 0, len - 1);
    convert_array_to_list(head_ref, arr, len);
    delete[] arr;
}


// COUNT NODE FUNCTION
int count_node(Record** head_ref) {
    // short way to get no of node 
    return length_of_list(head_ref);
}

Record* End_node(Record**head_ref){
    Record* curr = *head_ref;
    while (curr->next!=*head_ref){
        curr=curr->next;
    }
    return curr;
}

// MAIN FUNCTION
int main() {
    Record* head = NULL;

    insert(&head, 50);
    insert(&head, 20);
    insert(&head, 10);
    insert(&head, 60);
    insert(&head, 70);
    insert(&head, 30);

    cout << "Unsorted list:" << endl;
    print(&head);

    sorted_list(&head);

    cout << "Sorted list:" << endl;
    print(&head);

    cout << endl;

    int total = count_node(&head);
    cout << "The total node count is: " << total << endl;

    cout << endl;

    cout << "the address of first node is: " << &head << endl;
    cout << "the address of last node is: " << End_node(&head) << endl;

    return 0;
}
