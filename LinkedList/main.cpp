// Online C++ compiler to run C++ program online
#include <algorithm>
#include <iostream>
#include <Stdlib.h>
using namespace std;

struct Node{
    int data;
    Node *next  ;
};

Node *List = NULL;
Node* current_Position ;
void insert(int value ) {
// 1st storing memory
Node* current_memory = (Node*) malloc(sizeof(Node));

current_memory ->data = value;
    current_memory -> next = NULL;


    if (List == NULL) {
        List = current_memory;
    }
    else {
        Node* current_Position = List;
        if (current_Position->next == NULL) {
            current_Position -> next  = current_memory ;
        }
        else {
            while (current_Position->next != NULL) {
                current_Position =current_Position -> next;
            }
            current_Position->next = current_memory;

        }
    }


}

void display() {
    Node* current_Position = List;
    while (current_Position != NULL )  {

        int data  =  current_Position ->data;
        cout<<data<<endl;
        current_Position = current_Position ->next;
    }

}


void search(int value)   {
    int count = 0 ;
    bool found = false;
    Node* current_Position = List;
    while (current_Position != NULL && !found)  {
count++;
        int data  =  current_Position ->data;
        if (data == value) {
            found = true;
            cout<<"found: "<<data<<" at position of node :"<<count;
        }
        current_Position = current_Position ->next;
    }
    if (found == false) {
        cout<<"not found ";
    }

}

void Delete(int num){
    bool found = false;
    bool checkerdata = false;
    Node* current_Position = List;
    Node* pervious_position ;
    if (current_Position->data == num) {
      List = current_Position->next;
    }

    else {
            while (current_Position != NULL && !found) {

                int data  =  current_Position ->data;
                if (data == num) {
                    checkerdata = true;
                    found = true;
                    break;
                }
                pervious_position = current_Position;
                current_Position = current_Position ->next;}

           if (checkerdata) {
            current_Position = current_Position -> next;
            pervious_position -> next = current_Position ;
            }
            if (found == false) {
            cout<<"not found ";
            }
        }
}


int main() {

insert(18);
    insert(16);
    insert(20);
// search(18);
  Delete(20);
display();
};