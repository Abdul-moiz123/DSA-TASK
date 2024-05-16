#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

struct Record {
    int roll_no;
    int index;
    Record* next;
    Record* prev;
};


// INSERT FUNCTION
void insert(Record** head_ref, int data) {
    Record* ptr = (Record*)malloc(sizeof(Record));
    ptr->roll_no = data;
    ptr->next = NULL;
    ptr->prev = NULL;

    if (*head_ref == NULL) {
        ptr->index = 0;
        *head_ref = ptr;
    }
    
    else {
        Record* curr = *head_ref;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = ptr;
        ptr->index = curr->index + 1;
        ptr->prev=curr;
    }
}


// SEARCH FUNCTION
void search(Record** head_ref) {
    if (*head_ref == NULL) {
        cout << "the list is empty" << endl;
        return;
    }

    Record* curr = *head_ref;
    int tosearch;
    cout << "enter the roll no that you want to search: ";
    cin >> tosearch;

    while (curr != NULL) {
        if (curr->roll_no == tosearch) {
            cout << "the roll no is found to be: " << curr->roll_no << endl;
            cout << "the index is: " << curr->index << endl;
            cout << endl;
            return;
        }
        curr = curr->next;
    }
    cout << "the Record has not been found in the list" << endl;
}


// PRINT FUNCTION
void print(Record** head_ref) {
    if (*head_ref == NULL) {
        cout << "the list is empty" << endl;
        return;
    }

    Record* curr = *head_ref;

    while (curr != NULL) {
        cout << "the Index is: " << curr->index << endl;
        cout << "the roll no is found to be: " << curr->roll_no << endl;
        cout << endl;
        curr = curr->next;
    }
}


// DELETE VALUE FUNCTION
void delete_value(Record** head_ref, int todel) {
    if (*head_ref == NULL) {
        cout << "the list is empty" << endl;
        return;
    }

    Record* curr = *head_ref;
    Record* prev = NULL;

    if (curr->roll_no == todel) {
        *head_ref = curr->next;
        free(curr);

        Record* ind = *head_ref;
        while (ind != NULL) {
            ind->index--;
            ind = ind->next;
        }
        cout << "The Record has been deleted" << endl;
        return;
    }

    while (curr != NULL && curr->roll_no != todel) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "The Record has not been found in the list" << endl;
        return;
    }

    do{
        if(curr->roll_no==todel){
            if(prev!=NULL){
                prev->next = curr->next;
                Record* ind1 = prev->next;
                while (ind1 != NULL) {
                    ind1->index--;
                    ind1 = ind1->next;
                }
                free(curr);
            }
        }
    }while(curr!=NULL);
    cout << "The Record has been deleted" << endl;
}


// DELETE LIST FUNCTION
void delete_list(Record** head_ref) {
    if (*head_ref == NULL) {
        cout << "the list is already empty" << endl;
        return;
    }
    Record* curr = *head_ref;
    Record* next;
    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    *head_ref = NULL;
    cout << "The list has been deleted" << endl;
}


// LENGTH OF LIST FUNCTION
int length_of_list(Record** head_ref) {
    Record* curr = *head_ref;
    int len = 0;
    while (curr != NULL) {
        len++;
        curr = curr->next;
    }
    return len;
}


// CONVERT LIST TO ARRAY FUNCTION
void convert_list_to_array(Record** head_ref, int* arr) {
    Record* curr = *head_ref;
    int i = 0;
    while (curr != NULL) {
        arr[i] = curr->roll_no;
        curr = curr->next;
        i++;
    }
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
    Record* curr = *head_ref;
    int count = 0;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

Record* End_node(Record**head_ref){
    Record* curr = *head_ref;
    while (curr->next!=NULL){
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
    cout << "the total node is: " << total << endl;

    cout << endl;

    cout << "the address of first node is: " << &head << endl;
    cout << "the address of last node is: " << End_node(&head) << endl;
    return 0;
}
