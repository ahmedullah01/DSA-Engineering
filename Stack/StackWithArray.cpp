#include <iostream>
using namespace std;

int stack[5];
int top = -1;

// ---------------- Push ----------------
void push(int value){
    top++;
    if(top > 4){
        cout << "Stack is overflow \n";
        top--; // revert top
        return;
    }
    stack[top] = value;
}

// ---------------- Pop ----------------
void pop(){
    if(top == -1){
        cout << "Stack is underflow \n";
        return;
    }
    top--; // logical delete
}

// ---------------- Display ----------------
void display() {
    if(top == -1){
        cout << "Stack is empty \n";
        return;
    }
    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

// ---------------- Peek ----------------
void peek(){
    if(top == -1){
        cout << "Stack is empty \n";
        return;
    }
    cout << "Top element is: " << stack[top] << endl;
}

// ---------------- Main Menu ----------------
int main() {
    int choice, value;

    while(true){
        cout << "\n===== STACK MENU =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Peek\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                peek();
                break;

            case 5:
                cout << "Program terminated.\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}