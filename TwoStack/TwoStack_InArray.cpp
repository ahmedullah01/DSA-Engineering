#include <iostream>
using namespace std;




int array[10];
int top1 = -1;
int top2 = 10;


void push1(int x ){
    if((top1+1) == top2){
        cout << "Stack 1 is full" << endl;
        return;
    }
else{
    top1++;
    array[top1] = x;
}    
}

void push2(int x ){
    if((top2-1) == top1){
        cout << "Stack 2 is full" << endl;
        return;
    }
else{
    top2--;
    array[top2] = x;
}    }

void pop1(){
    if(top1 == -1){
        cout << "Stack 1 is empty" << endl;
        return;
    }
else{
    top1--;
}
}
void pop2() {
    if (top2 == 10) {
        cout << "Stack 2 is empty" << endl;
        return;
    }
    top2++;
}

void printStacks() {
    cout << "Stack 1: ";
    if (top1 == -1) {
        cout << "<empty>";
    } else {
        for (int i = 0; i <= top1; i++) {
            cout << array[i];
            if (i < top1) cout << ", ";
        }
    }
    cout << "\nStack 2: ";
    if (top2 == 10) {
        cout << "<empty>";
    } else {
        for (int i = 10; i > top2; i--) {
            cout << array[i - 1];
            if (i - 1 > top2) cout << ", ";
        }
    }
    cout << '\n';
}

int main() {
    cout << "Testing two stacks in one array:\n";

    push1(1);
    push1(2);
    push1(3);
    push2(9);
    push2(8);
    push2(7);

    printStacks();

    cout << "Popping one element from each stack...\n";
    pop1();
    pop2();
    printStacks();

    cout << "Adding more values to stack 2...\n";
    push2(6);
    push2(5);
    push2(4);
    push2(3);
    printStacks();

    cout << "Attempting one more push to stack 2 (should report full)\n";
    push2(2);

    cout << "Final state:\n";
    printStacks();
    return 0;
}
