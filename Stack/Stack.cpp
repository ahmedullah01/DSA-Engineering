#include <iostream>
using namespace std;

// Doubly Linked List Node
struct Stack {
    int data;
    Stack *NextAdd;
};

Stack *StackStart = NULL;

void Push(int value) {
    Stack *newNode = new Stack();//memory 
    newNode->data = value; //data dla

    //new node kay next mai purana stack start ko point karwa do that our simple stack will be created
    //stackstart hamesah new node ko point out krega  phelay purani wali ka connection dega new kay nect mai  phir khud new wali ko pint out krnay lgy ga

    newNode->NextAdd = StackStart;  
    StackStart = newNode;          
}

void pop(){
    if( StackStart == NULL ){
        cout<<"Stack is underflow \n";
        return;
    }
    //stactstart --> 15 --> 10 --> 5 --> NULL
    //temp --> 15 --> 10 --> 5 --> NULL
    //stackstart --> 10 --> 5 --> NULL
    //delete temp --> 15 --> 10 --> 5 --> NULL
    Stack* temp = StackStart;
    StackStart = StackStart->NextAdd;
    delete temp;
}

void show (){
    Stack* current = StackStart;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->NextAdd;
    }
    cout << endl;
}
int main() {
   Push(3);
   Push(5);
   Push(7);
   pop();
   show();
}