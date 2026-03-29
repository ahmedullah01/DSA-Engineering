#include <iostream>
using namespace std;

std::string ans  = "";
char stack[10];
int top = -1;



void prefix(char aplha) {

    ans += aplha;
}

void show() {
    std::cout<<ans;
}


int Precedence(char character) {
    switch (character) {
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        case'%':
            return 2;
        case '(':
            return 3;
        case ')':
            return 3;
            default:
            return -1;
    }
}



// ---------------- Push ----------------
void push(char value){
    top++;
    if(top > 10){
        std::cout << "Stack is overflow \n";
        top--; // revert top
        return;
    }
    stack[top] = value;
}

// ---------------- Pop ----------------
void pop() {
    if(top == -1){
        std::cout << "Stack is underflow \n";
        return ;
    }

    top--; // logical delete
}
char peek(){
    if(top == -1){

        return '@';
    }
     return stack[top];
}

void converter(std::string infix) {
    int count = 0;
    for (int i = 0 ; i <  infix.size() ; i++) {
        char a = infix.at(i);
        int asci = (int) a ;


        //agr to alphabet hai to direct add in answer
        if (asci>=97 && asci<=122) {
            prefix(a);
        }

        else {
            //push cases a)stack khali
            if (peek() == '@' && a != '(') {
                push(a);
            }

            //b)stack conmpare push krna hai
            else {
                int precedencecurr =Precedence(a);
                int precedenceprevious  =Precedence(peek());

                if (a == '(' ) {
                    count++;
                    push(a);
                }
                else if (a == ')') {
                    while (peek() != '(') {
                      prefix(peek());
                        pop();
                    }
                    pop();
                    count--;
                }

                else if ((precedenceprevious < precedencecurr) && count ==0 ) {
                    push(a);
                }
                else if (count >0) {
                    push(a);
                }
                else {
                       while ((precedenceprevious > precedencecurr) && top != -1 && count == 0) {
                       precedencecurr =Precedence(a);
                 precedenceprevious  =Precedence(peek());
                      prefix(peek());
                           pop();
                    }
                        push(a);
                }




            }

        }
    }





    while (top != -1) {

        prefix(peek() );
        pop();
    }
}

int main() {
    std::string infix = "(e+(c+b))";
    converter(infix);
    show();
}