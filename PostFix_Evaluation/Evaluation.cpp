#include <iostream>
#include <string>
using namespace std;

struct Node {
    double data;
    Node* next;
};

Node* top = NULL;


void push(double Val) {
    Node* NewNode = new Node();
    NewNode->data = Val;
    NewNode->next = top;
    top = NewNode;
}

double pop() {
    if (top == NULL) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    Node* temp = top;
    double val = temp->data;
    top = top->next;
    delete temp;
    return val;
}

double peek() {
    if (top == NULL) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return top->data;
}

void postfixEva(string equation) {
    for (int i = 0; i < equation.length(); i++) {

        if (equation[i] >= '0' && equation[i] <= '9') {
            double num = (double)(equation[i] - '0');
            cout<<num;
            push(num);
        } 
        else {
           double value1 = pop();
            double value2 = pop();
            double ans = 0;

            switch (equation[i]) {
                case '+':
                    ans = value2 + value1;
                    break;
                case '-':
                    ans = value2 - value1;
                    break;
                case '*':
                    ans = value2 * value1;
                    break;
                case '/':
                    if (value1 != 0)
                        ans = value2 / value1;
                    else {
                        cout << "Error: Division by zero!" << endl;
                        return;
                    }
                    break;
                default:
                    cout << "Invalid operator!" << endl;
                    return;
            }

            push(ans);
        }
    }

    cout << "Final Result: " << peek() << endl;
}

int main() {
    postfixEva("232*4/+12*54*2-2*+-");

}