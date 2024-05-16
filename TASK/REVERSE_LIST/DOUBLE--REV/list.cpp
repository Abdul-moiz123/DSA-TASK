// find the min and max value in the list
//  store address of first and last node
// reverse the list

#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;


struct Record{
    int data;
    Record* next;
    Record* prev;
};

Record* head = NULL;
Record* tail = NULL;

void insert(int data){
    Record* ptr = (Record*)malloc(sizeof(Record));
    ptr->data=data;
    ptr->next=NULL;
    ptr->prev=NULL;

    if(head==NULL){
        head=ptr;
        tail=ptr;
    }
    else{
        // we used the queue structure method ( front --> rear)
        tail->next=ptr;
        ptr->prev=tail;
        tail=ptr;
    }
}

void print(){
    Record* curr = head;
    while (curr!=NULL){
        cout << curr->data << " ";
        curr=curr->next;
    }
    cout << endl;
}

// REVERSE THE LIST
void reverse_list(){
    Record* curr = head;
    Record* momo = NULL;

    while (curr!=NULL){
        momo = curr->prev;
        curr->prev=curr->next;
        curr->next=momo;
        curr=curr->prev;
    }
    if(momo !=NULL){
        head = momo->prev;
    }
}

// min value in list
int find_min(){
    if(head==NULL){
        return -1;
    }
    Record* curr = head;
    int min =head->data;
    while (curr!=NULL){
        if(curr->data < min){
            min = curr->data;
        }
        else{
            curr=curr->next;
        }
    }
    return min;
}

// max value in list
int find_max(){
    if(head==NULL){
        return -1;
    }
    Record* curr = head;
    int max =head->data;
    while (curr!=NULL){
        if(curr->data > max){
            max = curr->data;
        }
        else{
            curr=curr->next;
        }
    }
    return  max;
}


int main(){

    insert(100);
    insert(211);
    insert(321);
    insert(413);
    insert(541);
    insert(165);
    cout << endl;
    print();
    cout << endl;
    reverse_list();
    cout << endl;
    print();
    cout << endl;
    cout << find_max();
    cout << endl;
    cout << find_min();
    cout << endl;

   return 0;
}